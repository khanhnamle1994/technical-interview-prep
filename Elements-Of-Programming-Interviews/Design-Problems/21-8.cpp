The PageRank algorithm assigns a rank to a web page based on the number of "important" pages that link to it. The algorithm essentially
amounts to the following:

(1) Build a matrix A based on the hyperlink structure of the web. Specifically, A_ij = 1/d_j if page j links to page i; here d_j is the
number of distinct pages linked from page j.

(2) Find X satisfying X = e[1] + (1 - e)AX. Here e is a constant. The value X[i] is the rank of the ith page.

The most commonly used approach to solving the above equation is to start with a value of X, where each component is 1/n (where n is the
number of pages) and then perform the following iteration: X_k = e[1] + (1 - e)AX_(k - 1). The iteration stops when the X_k converges.

Design a system that can compute the ranks of 10 billion webpages in a reasonable amount of time.

Solution:

Since the web graph can have billions of verties and it is mostly a sparse graph, it is best to represent the graph as an adjacency list.
Building the adjacency list representation of the graph may require a significant amount of computation, depending upon how the information
is collected. Usually, the graph is constructed by downloading the pages on the web and extracting the hyperlink information from the
pages. Since the URL of a page can vary in length, it is often a good idea to represent the URL by a hash code.

The most expensive part of the PageRank algorithm is the repeated matrix multiplication. Usually, it is not possible to keep the entire
graph information in a single machine's RAM. Two approaches to solving this problem are described below:

* Disk-based sorting - we keep the column vector X in memory and load rows one at a time. Processing Row i simply requires adding A_{i,j}
X_j to X_j for each j such that A_{i,j} is not zero. The advantage of this approach is that if the column vector fits in RAM, the entire
computation can be performed on a single machine. This approach is slow because it uses a single machine and relies on the disk.

* Partitioned graph - we use n servers and partition the vertices (webpages) into n sets. This partition can be computed by partitioning
the set of hash codes in such a way that it is easy to determine which vertex maps to which machine. Given this partitioning, each machine
loads its vertices and their outgoing edges into RAM. Each machine also loads the portion of the PageRank vector corresponding to the
vertices it is responsible for. Then each machine does a local matrix multiplication. Some of the edges on each machine may correspond
to vertices that are owned by other machines. Hence the result vector contains nonzero entries for vertices that are not owned by the
local machine. At the end of the local multiplication, it needs to send updates to other hosts so that these values can be correctly added
up. The advantage of this approach is that it can process aribitrarily large graphs.

PageRank runs in minutes on a single machine on the graph consisting of the multimillion pages that constitute Wikipedia. It takes roughly
70 iterations to converge on this graph. Anecdotally, PageRank takes roughly 200 iterations to converge on the graph consisting of the
multimillion pages that constitute the World-Wide-Web.

When operating on a graph the scale of the webgraph, PageRank must be run on many thousands of machines. In such situations, it is very
likely that a machine will fail. The widely used Map-Reduce framework handles efficient parallelization as well as fault-tolerance. Roughly
speaking, fault-tolerance is achieved by replicating data across a distributed file system, and having the master reassign jobs on machines
that are not responsive.
