// You left your computer unlocked and your friend decided to troll you by copying a lot of your files to random spots all over your file system.

// Even worse, she saved the duplicate files with random, embarrassing names ("this_is_like_a_digital_wedgie.txt" was clever, I'll give her that).

// Write a function that returns a vector of all the duplicate files. We'll check them by hand before actually deleting them, since programmatically deleting files is really scary. To help us confirm that two files are actually duplicates, return a vector of FilePaths objects with variables for the original and duplicate paths:

class FilePaths
{
public:
    string duplicatePath_;
    string originalPath_;

    FilePaths(const string& duplicatePath, const string& originalPath) :
        duplicatePath_(duplicatePath),
        originalPath_(originalPath)
    {
    }

    string toString() const
    {
        ostringstream str;
        str  << "(original: " << filePaths.originalPath_
            << ", duplicate: " << filePaths.duplicatePath_ << ")";
        return str.str();
    }
};

// For example:
(original: /home/parker/secret_puppy_dance.mpg, duplicate: /tmp/parker_is_dumb.mpg)
(original: /etc/apache2/httpd.conf, duplicate: /home/trololol.mov)

// You can assume each file was only duplicated once.


// Solution
// We walk through our whole file system iteratively. As we go, we take a "fingerprint" of each file in constant time by hashing the first few, middle few, and last few bytes. We store each file's fingerprint in an unordered map as we go.

// If a given file's fingerprint is already in our unordered map, we assume we have a duplicate. In that case, we assume the file edited most recently is the one created by our friend.

#include <cstring>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <openssl/sha.h>

using namespace std;

class FilePaths
{
public:
    string duplicatePath_;
    string originalPath_;

    FilePaths(const string& duplicatePath = string(),
            const string& originalPath = string()) :
        duplicatePath_(duplicatePath),
        originalPath_(originalPath)
    {
    }

    string toString() const
    {
        ostringstream str;
        str  << "(original: " << filePaths.originalPath_
            << ", duplicate: " << filePaths.duplicatePath_ << ")";
        return str.str();
    }
};

class FileInfo
{
public:
    string path_;
    time_t lastModified_;

    FileInfo(const string& path, time_t lastModified) :
        path_(path),
        lastModified_(lastModified)
    {
    }
};


// We wrap our directory handle in a class to make it exception safe
// and ensure the directory always gets closed.
class DirectoryHandle
{
public:
    DIR* dir_;

    DirectoryHandle(const char* path) :
        dir_(opendir(path))
    {
    }

    ~DirectoryHandle()
    {
        if (_dir != nullptr) {
            closedir(dir_);
        }
    }
};

void scanDirectory(const string& directoryPath, stack<string>& pathsStack)
{
    DirectoryHandle dir(directoryPath.c_str());
    if (dir.dir_) {
        struct dirent* entry;
        while ((entry = readdir(dir.dir_)) != nullptr) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                string path = directoryPath + '/' + entry->d_name;
                pathsStack.push(path);
            }
        }
    }
}

vector<unsigned char> sampleFileData(const string& path)
{
    // read file attributes
    struct stat st;
    if (stat(path.c_str(), &st) < 0) {
        ostringstream errorMessage;
        errorMessage << "Can't stat file '" << path << "'." << endl;
        throw runtime_error(errorMessage.str());
    }
    if (!S_ISREG(st.st_mode)) {
        ostringstream errorMessage;
        errorMessage << "File '" << path << "' is not a regular file.";
        throw runtime_error(errorMessage.str());;
    }

    // determine how much to read from file
    const off_t BLOCK_SIZE = 4000;
    const off_t MAX_DATA_SIZE = BLOCK_SIZE * 3;
    const off_t dataSize = std::min(st.st_size, MAX_DATA_SIZE);

    // reserve storage of the appropriate size for file data
    vector<unsigned char> fileData(dataSize);

    // Read the file using low-level system call based file I/O.
    // (C++ STL may not properly handle files larger than 2 GB.)

    // Open file
    int fd = open(path.c_str(), O_RDONLY);
    if (fd != -1) {

        // file opened, read it
        ssize_t readLength  = 0;

        // If size is too small to take 3 samples, read the entire file
        // into the provided buffer, updating readLength.
        if (dataSize <= MAX_DATA_SIZE) {
            readLength = read(fd, static_cast<void*>(&fileData[0]), dataSize);
        }

        // Otherwise, read the samples into the buffer at the right offsets,
        // and update the readLength.
        else {
            readLength += read(fd,
                static_cast<void*>(&fileData[0]), BLOCK_SIZE);
            if (lseek(fd, (st.st_size / 2) - (BLOCK_SIZE / 2), SEEK_SET) == (off_t) -1) {
                throw runtime_error("Can't lseek file.");
            }
            readLength += read(fd,
                static_cast<void*>(&fileData[BLOCK_SIZE]), BLOCK_SIZE);
            if (lseek(fd, -BLOCK_SIZE, SEEK_END) == (off_t) -1) {
                throw runtime_error("Can't lseek file.");
            }
            readLength += read(fd,
                static_cast<void*>(&fileData[BLOCK_SIZE * 2]), BLOCK_SIZE);
        }

        close(fd);

        // Check whether we have read proper number of bytes
        if (readLength != dataSize) {
            ostringstream errorMessage;
            errorMessage << "Couldn't read file '" << path << "'.";
            throw runtime_error(errorMessage.str());
        }
    }

    // file wasn't opened
    else {
        ostringstream errorMessage;
        errorMessage << "Couldn't open file '" << path << "' for reading.";
        throw runtime_error(errorMessage.str());
    }

    return fileData;
}

string sampleFileHash(const string& path)
{
    try {
        // get data from file
        vector<unisgned char> fileData = sampleFileData(path);

        // compute SHA-512 hash
        ostringstream result;
        unsigned char hashValue[SHA512_DIGEST_LENGTH];
        SHA512(&fileData[0], fileData.size(), hashValue);
        result << hex;
        for (size_t i = 0; i < SHA512_DIGEST_LENGTH; ++i) {
            if (hashValue[i] < 16) {
                result << '0';
            }
            result << static_cast<unsigned int>(hashValue[i]);
        }

        return result.str();
    }
    catch (exception& ex) {
        cerr << "Error: " << ex.what() << endl;
        return string();
    }
}

vector<FilePaths> findDuplicateFiles(const string& startingDirectory)
{
    unordered_map<string, FileInfo> filesSeenAlready;
    stack<string> pathsStack;
    pathsStack.push(startingDirectory);

    vector<FilePaths> duplicates;

    while (!pathsStack.empty()) {

        string currentPath = pathsStack.top();
        pathsStack.pop();

        struct stat st;
        if (stat(currentPath.c_str(), &st) < 0) {
            cerr << "Error: Can't stat file '" << currentPath << "'." << endl;
            continue;
        }

        // if it's a directory,
        // put the contents in our stack
        if (S_ISDIR(st.st_mode)) {
            scanDirectory(currentPath, pathsStack);
        }

        // if it's a file
        else if (S_ISREG(st.st_mode)) {
            string hash = sampleFileHash(currentPath);

            // if we've seen it before
            if (!hash.empty()) {
                auto it = filesSeenAlready.find(hash);
                if (it != filesSeenAlready.end()) {

                    // compare with its last edited time
                    if (st.st_mtime > it->second.lastModified_) {

                        // current file is the dupe!
                        duplicates.emplace(duplicates.end(), currentPath, it->second.path_);
                    }
                    else {

                        // old file is the dupe!
                        duplicates.emplace(duplicates.end(), it->second.path_, currentPath);

                        // but also update filesSeenAlready to have the new file's info
                        it->second.path_ = currentPath;
                        it->second.lastModified_ = st.st_mtime;
                    }
                }

                // if it's a new file, throw it in filesSeenAlready
                // and record its path and last edited time,
                // so we can tell later if it's a dupe
                else {
                    filesSeenAlready.insert(make_pair(hash, FileInfo(currentPath, st.st_mtime)));
                }
            }
        }
    }

    return duplicates;
}

// We've made a few assumptions here:

// Two different files won't have the same fingerprints. It's not impossible that two files with different contents will have the same beginning, middle, and end bytes so they'll have the same fingerprints. Or they may even have different sample bytes but still hash to the same value (this is called a "hash collision"). To mitigate this, we could do a last-minute check whenever we find two "matching" files where we actually scan the full file contents to see if they're the same.

// The most recently edited file is the duplicate. This seems reasonable, but it might be wrong—for example, there might be files which have been edited by daemons (programs that run in the background) after our friend finished duplicating them.

// Two files with the same contents are the same file. This seems trivially true, but it could cause some problems. For example, we might have empty files in multiple places in our file system that aren't duplicates of each-other.

// Given these potential issues, we definitely want a human to confirm before we delete any files. Still, it's much better than combing through our whole file system by hand!

// Complexity
// Each "fingerprint" takes O(1)O(1) time and space, so our total time and space costs are O(n)O(n) where nn is the number of files on the file system.

// If we add the last-minute check to see if two files with the same fingerprints are actually the same files (which we probably should), then in the worst case all the files are the same and we have to read their full contents to confirm this, giving us a runtime that's order of the total size of our files on disc.
