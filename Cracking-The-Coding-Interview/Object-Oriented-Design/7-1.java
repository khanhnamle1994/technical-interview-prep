// Design the data structures for a generic deck of cards. Explain how you would subclass it to implement particular card games.

// Assume that we’re building a blackjack game, so we need to know the value of the cards.
// Face cards are ten and an ace is 11 (most of the time, but that’s the job of the Hand class, not the following class).

public class BlackJackCard extends Card {
    public BlackJackCard(int r, Suit s) {
        super(r, s);
    }

    public int value() {
        int r = super.value();
        if (r == 1) return 11; // aces are 11
        if (r < 10) return r;
        return 10;
    }

    boolean isAce() {
        return super.value() == 1;
    }
}
public class Card {
    public enum Suit {
        CLUBS (1),
        SPADES (2),
        HEARTS (3),
        DIAMONDS (4);

        int value;
        private Suit(int v) { value = v; }
    };

    private int card;
    private Suit suit;

    public Card(int r, Suit s) {
        card = r;
        suit = s;
    }

    public int value() { return card; }
    public Suit suit() { return suit; }
}
