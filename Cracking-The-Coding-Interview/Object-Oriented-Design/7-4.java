// Design a chess game using object oriented principles.

//include info about timing, etc.
public class ChessFormat {

}

public abstract class ChessPieceBase {
    abstract void estimationParameter0(); /* used by PositionEstimater in different circumstances */
    abstract int estimationParameter1();
    abstract boolean canBeChecked();
    abstract boolean isSupportCastle();
    // other rule-base properties
}

public class ChessPieceTurn {

}

class ComputerPlayer extends PlayerBase {
    public ChessPieceTurn getTurn(Position p) { return null; }
    public void setDifficulty() { };
    public PositionEstimator estimater;
    public PositionBackTracker backtracter;
}

public class GameManager { // keeps track of time, end of the game, etc
    void processTurn(PlayerBase player) { };
    boolean acceptTurn(ChessPieceTurn turn) { return true; };

    Position currentPosition;
    ChessFormat format;
    public void setGameLog(String filePath) { };
}

public class HumanPlayer extends PlayerBase {
    public ChessPieceTurn getTurn(Position p) { return null; }
}

public class King extends ChessPieceBase {
    void estimationParameter0() { };
    int estimationParameter1() { return 0; }
    boolean canBeChecked() { return false; }
    boolean isSupportCastle() { return false; }
}

public abstract class PlayerBase {
    public abstract ChessPieceTurn getTurn(Position p);
}

public class PositionBackTracker {
    // get next position for estimation.
    public static Position getNext(Position p) { return null; }
}

public class PositionEstimator {
    // calculate value of a position
    public static PositionPotentialValue estimate(Position p) { return null; }
}

import java.util.ArrayList;

public class Position { // represents chess positions in compact form
    ArrayList<ChessPieceBase> black;
    ArrayList<ChessPieceBase> white;
}

public abstract class PositionPotentialValue {
    /* compares value of potential game position */
    abstract boolean lessThan(PositionPotentialValue pv);
}

public class Queen extends ChessPieceBase {
    void estimationParameter0() { };
    int estimationParameter1() { return 0; }
    boolean canBeChecked() { return false; }
    boolean isSupportCastle() { return false; }
}
