// Design a musical juke box using object oriented principles.

/*
Let’s first understand the basic system components:
»» CD player
»» CD
»» Display () (displays length of song, remaining time and playlist)
Now, let’s break this down further:
»» Playlist creation (includes add, delete, shuffle etc sub functionalities)
»» CD selector
»» Track selector
»» Queueing up a song
»» Get next song from playlist
A user also can be introduced:
»» Adding
»» Deleting
»» Credit information
How do we group this functionality based on Objects (data + functions which go together)?
Object oriented design suggests wrapping up data with their operating functions in a single entity class.
*/

public class CD {

}

public class CDPlayer {
    private Playlist p;
    private CD c;

    public Playlist getPlaylist() { return p; }
    public void setPlaylist(Playlist p) { this.p = p; }
    public CD getCD() { return c; }
    public void setCD(CD c) { this.c = c; }

    public CDPlayer(Playlist p) { this.p = p; }
    public CDPlayer(CD c, Playlist p) {
        this.p = p;
        this.c = c;
    }

    public CDPlayer(CD c){ this.c = c; }
    public void playTrack(Song s) {  }
}

public class JukeBox {
    private CDPlayer cdPlayer;
    private User user;
    private Set<CD> cdCollection;
    private TrackSelector ts;

    public JukeBox(CDPlayer cdPlayer, User user, Set<CD> cdCollection,
                   TrackSelector ts) {
        super();
        this.cdPlayer = cdPlayer;
        this.user = user;
        this.cdCollection = cdCollection;
        this.ts = ts;
    }

    public Song getCurrentTrack() { return ts.getCurrentSong(); }
    public void processOneUser(User u) { this.user = u; }
}

public class Playlist {
    private Song track;
    private Queue<Song> queue;
    public Playlist(Song track, Queue<Song> queue) {
        super();
        this.track = track;
        this.queue = queue;
    }

    public Song getNextTrackToPlay(){ return queue.peek(); }
    public void queueUpTrack(Song s){ queue.add(s); }
}

public class Song {
    private String songName;
    public String toString() { return songName; }
}

public class TrackSelector {
    private Song currentSong;
    public TrackSelector(Song s) { currentSong=s; }
    public void setTrack(Song s) { currentSong = s; }
    public Song getCurrentSong() { return currentSong;  }
}

public class User {
    private String name;
    public String getName() { return name; }
    public void setName(String name) {  this.name = name; }
    public long getID() { return ID; }
    public void setID(long iD) { ID = iD; }
    private long ID;
    public User(String name, long iD) {
        this.name = name;
        ID = iD;
    }
    public User getUser() { return this; }
    public static User addUser(String name, long iD){
        return new User(name, iD);
    }
}
