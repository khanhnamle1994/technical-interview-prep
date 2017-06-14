Keyword-based search engines maintain a collection of several billion documents. One of the key documentations performed by a search
engine is to retrieve all the documents that contain the keywords contained in the query. This is a nontrivial task in part because it
must be performed in a few tens of milliseconds. Here we consider a smaller version of the problem where the collection of documents can
fit within the RAM of a single computer.

Given a million documents with an average size of 10 kilobytes, design a program that can efficiently return the subset of documents
containing a given set of words.

Solution:

The predominant way of doing this is to build inverted indices. In an inverted index, for each word, we store a sequence of locations
where the word occurs. The sequence itself could be represented as an array or a linked list. Location is defined to be the document ID
and the offset in the document. The sequence is stored in sorted order of locations (first ordered by document ID, then by offset). When
we are looking for documents that contains a set of words, what we need to do is find the intersection of sequences for each word. Since
the sequences are already sorted, the intersection can be done in time proportional to the aggregate length of the sequences. We list a
few optimizations below:

* Compression - compressing the inverted index helps both with the ability to index more documents as well as memory locality (fewer cache
misses). Since we are storing sorted sequences, one way of compressing is to use delta compression where we only store the difference
between the successive entries. The deltas can be represented in fewer bits.

* Caching - the distribution of queries is usually fairly skewed and it helps a great deal to cahe the results of some of the most
frequent entries.

* Frequency-based optimization - since search results often do not need to return every document that matches (only top 10 or so), only
a fraction of highest quality document can be used to answer most of the queries. This means that we can make 2 inverted indices, one
with the high quality documents that stays in RAM and one with the remaining documents that stays on disk. This way if we can keep the
number of queries that require the secondary index to a small enough number, then we can still maintain a reasonable throughput and latency.

* Intersection order - since the total intersection time depends on the total size of sequences, it would make sense to intersect the
words with smaller sets first.

We could also build a multilevel index to improve accuracy on documents. For a high priority webpage, we can decompose the page into
paragraphs and sentences, which are indexed individually. That way the intersections for the words might be within the same context. We
can pick results with closer index values from these sequences.
