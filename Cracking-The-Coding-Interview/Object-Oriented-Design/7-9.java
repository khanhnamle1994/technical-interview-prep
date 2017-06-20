// Explain the data structures and algorithms that you would use to design an in-memory file system.
// Illustrate with an example in code where possible.

// For data block allocation, we can use bitmask vector and linear search (see “Practical File System Design”) or B+ trees (see Wikipedia).

struct DataBlock { char data[DATA_BLOCK_SIZE]; };
DataBlock dataBlocks[NUM_DATA_BLOCKS];
struct INode { std::vector<int> datablocks; };

struct MetaData {
  int size;
  Date last_modifed, created;
  char extra_attributes;
};

std::vector<bool> dataBlockUsed(NUM_DATA_BLOCKS);
std::map<string, INode *> mapFromName;
struct FSBase;
struct File : public FSBase {
private:
  std::vector<INode> * nodes;
  MetaData metaData;
};

struct Directory : pubic FSBase { std::vector<FSBase* > content; };
struct FileSystem {
  init();
  mount(FileSystem*);
  unmount(FileSystem*);
  File createFile(cosnt char* name) { ... }
  Directory createDirectory(const char* name) { ... }

  // mapFromName to find INode corresponding to file
  void openFile(File * file, FileMode mode) {    ... }
  void closeFile(File * file) { ... }
  void writeToFile(File * file, void * data, int num) { ... }
  void readFromFile(File* file, void* res, int numbutes, int position) { ... }
};
