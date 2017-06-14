Jingle wants to generate more page views on its news site. A product manager has the idea to add to each article a sidebar of clickable
snippets from articles that are likely to be of interest to someone reading the current article.

Design a system that automatically generates a sidebar of related articles.

Solution:

The key technical challenges in this problem is to come up with the list of articles - the code for adding these to a sidebar is trivial.

One suggestion might be to add articles that have proved to be popular recently. Another is to have links to recent news articles. A human
reader at Jingle could tag articles which he believes to be significant. He could also add tags such as finance, sports, and politics,
to the articles. These tags could also come from the HTML, meta-tags or the page title.

We could also provide randomly selected articles to a random subset of readers and see how popular these articles prove to be. The popular
articles could then be shown more frequently.

On a more sophisticated level, Jingle could use automatic textual analysis, where a similarity is defined between pairs of articles - this
similarity is a real number and measures how many words are common to the two. Several issues come up, such as the fact that frequently
occurring words such as "for" and "the" should be ignored and that having rare words such as "arbitrage" and "diesel" in common is more
significant than having say, "sale" and "international".

Textual analysis has problems, such as the fact that 2 words may have the same spelling but completely different meanings. One way to augment
textual analysis is to use collaborative filtering - using information gleaned from many users. For example, by examining cookies and timestamps
in the web server's log files, we can tell what articles individual users have read. If we see many users have read both A and B in a
single session, we might want to recommend B to anyone reading A. For collaborative filtering to work, we need to have many users.
