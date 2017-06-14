Design the World Wide Web. Specifically, describe what happens when you enter a URL in a browser address bar, and press return.

Solution:

At the network level, the browser extracts the domain name component of the URL, and detemrines the IP address of the server, e.g., through
a call to a Domain Name Server (DNS), or a cache lookup. It then communicates using the HTTP protocol with the server. HTTP itself is
built on top of TCP/IP, which is responsible for routing, reassembling, and resending packets, as well as controlling the transmission rate.

The server determines what the client is asking for by looking at the portion of the URL that comes after the domain name, and possibly also
the body of the HTTP request. The request may be for something as simple as a file, which is returned by the webserver; HTTP spells out
a format by which the type of the returned file is specified.

The URL may also encode a request to a service provided by the web server. The service could be implemented in many ways, e.g., Java code
within the server, or a CGI script written in Perl. The service generates a HTTP response, typically HTML, which is then returned to the
browser. This response could encode data which is used by scripts running in the browser. Common data formats include JSON and XML.

The browser is responsible for taking the returned HTML and displaying it on the client. The rendering is done in 2 parts. First, a parse
tree (the DOM) is generated from the HTML, and then a rendering library "paints" the screen. The returned HTML may include scripts written
in JavaScript. These are executed by the browser, and they can perform actions like making requests and updating the DOM based on the
responses - this is how a live stock ticker is implemented. Styling attributes (CSS) are commonly used to customize the look of a page.

Many more issues exist on both the client and server side: security, cookies, HTML form elements, HTML styling, and handlers for multi-
media content, to name a few.
