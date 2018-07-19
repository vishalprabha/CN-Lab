## Computer Networks Lab

### Questions:
#### Part A: Implement the following using C/C++:

- Using TCP/IP sockets, write a client-server program to make client send the file name and the server to send back the contents of the requested file name “sample.txt” with the following contents: “Hello we are at Computer Networks Lab”  Display suitable error message in case the file is not present in the server.
- Write a program to archive Traffic management at Flow level by implementing Leaky Bucket Algorithm.
- Given a graph, each node A knows the shortest path to node Z and node A can determine its shortest path to Z by calculating the minimum cost. Now when packet flows through a path it incurs some cost to the network, find shortest paths from src to all nodes in the given graph using Bellman Ford Algorithm. The graph may contain negative weight edges.
- Given a graph find shortest paths from source to all nodes in the graph using Dijkstra’s shortest path algorithm.
- Write a program for implementing the error detection technique for data transfer in unreliable network code using CRC (16-bits) Technique.
- Write a program to implement internet checksum for error correction and detection.
- Packets from different flows arrive at a switch or router for processing. A good scheduling technique treats the different flows in a fair and  appropriate manner. Implement priority queuing as a technique to improve Quality of Service.

#### Part B: Simulation Using NS-2:

- Simulate three nodes point-to-point networks with duplex links between them. Set the queue size and vary the bandwidth and find the number of packets dropped
- Simulate the different types of internet traffic such as FTP and TELNET over network and analyze the throughput
- Simulate a four-node point-to-point network, and connect the links as follows: n0->n2, n1->n2 and n2->n3. Apply TCP agent changing the parameters and determine the number of packets sent/received by TCP/UDP
- Simulate the transmission of ping messages over a network topology consisting of 6 nodes and find the number of packets dropped due to congestion.
- Simulate an Ethernet LAN using n nodes and set multiple traffic nodes and determine collision across different nodes.
- Simulate an Ethernet LAN using n nodes (6-10), change error rate and data rate and compare throughput.
