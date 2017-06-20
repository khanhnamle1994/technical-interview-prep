// Design the data structures for an online book reader system.

/*
Since the problem doesn’t describe much about the functionality, let’s assume we want to design a basic online reading system which
provides the following functionality:

»» User membership creation and extension.
»» Searching the database of books
»» Reading the books

To implement these we may require many other functions, like get, set, update, etc. Objects required would likely include User, Book,
and Library. The following code / object oriented design describes this functionality:

This design is a very simplistic implementation of such a system. We have a class for User to keep all the information regarding the user,
and an identifier to identify each user uniquely. We can add functionality like registering the user, charging a membership amount and
monthly / daily quota, etc.

Next, we have book class where we will keep all the book’s information. We would also implement functions like add / delete / update books.

Finally, we have a manager class for managing the online book reader system which would have a listen function to listen for any incoming
requests to log in. It also provides book search functionality and display functionality. Because the end user interacts through this
class, search must be implemented here. */

public class User {
    private long ID;
    private String details;
    private int accountType;
    private static Set<User> users;

    public Book searchLibrary(long id){ return Book.find(id); }
    public void renewMembership() {  }

    public static User find(long ID) {
        for (User u:users) {
            if (u.getID() == ID) return u;
        }
        return null;
    }

    public static void addUser(long ID, String details,
                                int accountType) {
        users.add(new User(ID,details,accountType));
    }

    public User(long iD, String details, int accountType) {
        ID = iD;
        this.details = details;
        this.accountType = accountType;
    }
    public long getID() { return ID; }
    public void setID(long iD) { ID = iD; }
    public String getDetails() { return details; }
    public void setDetails(String details) { this.details = details; }
    public int getAccountType() { return accountType; }
    public void setAccountType(int accountType) {
        this.accountType = accountType;
    }
}

public class Book {
    private long ID;
    private String details;
    private static Set<Book> books;

    public Book(long iD, String details) {
        ID = iD;
        this.details = details;
    }

    public static void addBook(long iD, String details){
        books.add(new Book(iD,details));
    }

    public void update() { }

    public static void delete(Book b){
        books.remove(b);
    }

    public static Book find(long id){
        for (Book b : books) {
            if(b.getID() == id) return b;
        }
        return null;
    }

    public long getID() { return ID; }
    public void setID(long iD) { ID = iD; }
    public String getDetails() { return details; }
    public void setDetails(String details) { this.details = details; }
}

public class OnlineReaderSystem {
  private Book b;
  private User u;
  public OnlineReaderSystem(Book b, User u) {
      this.b = b;
      this.u = u;
  }

  public void listenRequest() { }
  public Book searchBook(long ID) { return Book.find(ID); }
  public User searchUser(long ID){ return User.find(ID); }
  public void display() { }
  public Book getBook() { return b; }
  public void setBook(Book b) { this.b = b; }
  public User getUser() { return u; }
  public void setUser(User u) { this.u = u; }
}
