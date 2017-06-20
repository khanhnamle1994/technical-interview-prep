// Imagine you have a call center with three levels of employees: fresher, technical lead (TL), product manager (PM). There can be
// multiple employees, but only one TL or PM.  An incoming telephone call must be allocated to a fresher who is free. If a fresher can’t
// handle the call, he or she must escalate the call to technical lead. If the TL is not free or not able to handle it, then the call
// should be escalated to PM. Design the classes and data structures for this problem. Implement a method getCallHandler().

/* All three ranks of employees have different work to be done, so those specific functions are profile specific. We should keep these
specific things within their respective class.

There are a few things which are common to them, like address, name, job title, age, etc.  These things can be kept in one class and can
be extended / inherited by others.

Finally, there should be one CallHandler class which would route the calls to the concerned person.

On any object oriented design question, there are many ways to design the objects. Discuss the trade-offs of different solutions with
your interviewer.  You should usually design for long term code flexibility and maintenance. */

class Call {
    int rank = 0; // minimal rank of employee who can handle this call

    public void reply(String message) {
        // play recorded message to the customer
    }

    public void disconnect() {
        reply("Thank you for calling");
    }
}

class Employee {
    CallHandler callHandler;
    int rank; // 0- fresher, 1 - technical lead, 2 - product manager
    boolean free;

    public Employee(int rank) {
        this.rank = rank;
    }

    // start the conversation
    void ReceiveCall(Call call) {
        free = false;
    }

    // the issue is resolved, finish the call
    void CallHandled(Call call) {
        call.disconnect();
        free = true;
        // look if there is a call waiting in queue
        callHandler.getNextCall(this);
    }

    // the issue is not resolved, escalate the call
    void CannotHandle(Call call) {
        call.rank = rank + 1;
        callHandler.dispatchCall(call);
        free = true;
        // look if there is a call waiting in queue
        callHandler.getNextCall(this);
    }
}

class Fresher extends Employee {
    public Fresher() {
        super(0);
    }
}

class TechLead extends Employee {
   public TechLead() {
       super(1);
   }
}

class ProductManager extends Employee {
   public ProductManager() {
       super(2);
   }
}

public class CallHandler {
    static final int LEVELS = 3; // we have 3 levels of employees
    static final int NUM_FRESHERS = 5; // we have 5 freshers

    ArrayList<Employee>[] employeeLevels = new ArrayList[LEVELS];

    // queues for each call抯 rank
    Queue<Call>[] callQueues = new LinkedList[LEVELS];

    public CallHandler() {
        // create freshers
        ArrayList<Employee> freshers = new ArrayList(NUM_FRESHERS);
        for (int k = 0; k < NUM_FRESHERS - 1; k++) {
            freshers.add(new Fresher());
        }
        employeeLevels[0] = freshers;

        // create technical lead
        ArrayList<Employee> tls = new ArrayList(1);
        tls.add(new TechLead()); // we have 1 technical lead
        employeeLevels[1] = tls;

        // create product manager
        ArrayList<Employee> pms = new ArrayList(1);
        pms.add(new ProductManager()); // we have 1 product manager
        employeeLevels[1] = pms;
    }

    Employee getCallHandler(Call call) {
        for (int level = call.rank; level < LEVELS - 1; level++) {
            ArrayList<Employee> employeeLevel = employeeLevels[level];
            for (Employee emp : employeeLevel) {
                if (emp.free) {
                    return emp;
                }
            }
        }
        return null;
    }

    // routes the call to an available employee, or saves in a queue
    // if no employee available
    void dispatchCall(Call call) {
        // try to route the call to an employee with minimal rank
        Employee emp = getCallHandler(call);
        if (emp != null) {
            emp.ReceiveCall(call);
        } else {
            // place the call into corresponding call queue according to
            // its rank
            call.reply("Please wait for free employee to reply");
            callQueues[call.rank].add(call);
        }
    }

    // employee got free, look for a waiting call he/she can serve
    void getNextCall(Employee emp) {
        // check the queues, starting from the highest rank this
        // employee can serve
        for (int rank = emp.rank; rank >= 0; rank--) {
            Queue<Call> que = callQueues[rank];
            Call call = que.poll(); // remove the first call, if any
            if (call != null) {
                emp.ReceiveCall(call);
                return;
            }
        }
    }
}
