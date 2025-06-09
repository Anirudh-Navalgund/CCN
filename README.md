# Computer Communication Networks
### Experiments based on different concepts of CCN carried out using Juniper EX2300-C running on JUNOS-OS  
### List of experiments:
- Cyclic Redundancy Check
- Chat (Client - Server)
- Echo (Client - Server)
- FTP (Client - Server)
- Single Switch VLAN
- Two Switch VLAN
- VLAN with Trunk Link
- DHCP
- OSPF
- IBGP

---

### 1. Cyclic Redundancy Check (CRC)
Cyclic Redundancy Check is an error-detection technique used to ensure the integrity of transmitted data. It treats the data as a polynomial and divides it by a predefined generator polynomial. The remainder is appended to the data before transmission and rechecked at the receiver's end. CRC is widely used in networking and storage for its efficiency and high error-detection capability.

### 2. Chat Application (TCP Client-Server)
This experiment demonstrates full-duplex communication between a client and a server using TCP sockets. It allows both sides to send and receive messages over a persistent, reliable connection. The setup helps understand socket programming, port allocation, and bidirectional data flow. It forms the basis for real-time applications like messaging and VoIP.

### 3. Echo Client-Server
The Echo protocol is a simple application where a client sends data to a server, which then echoes the data back unchanged. It is used to test network connectivity, reliability, and response time. This experiment illustrates TCP connection setup, message transfer, and basic socket functions. It’s often the first step in learning network programming.

### 4. FTP Simulation
This experiment simulates the File Transfer Protocol using TCP sockets to transfer data between a client and a server. It involves file upload (STOR) and download (RETR) functionalities. FTP uses a control connection for commands and a data connection for actual file transfer. Understanding FTP introduces students to layered protocol behavior and session management.

### 5. Single Switch VLAN
A VLAN (Virtual Local Area Network) allows network segmentation within a single switch by logically grouping ports. It helps isolate broadcast domains, improving security and traffic management. This experiment involves configuring VLAN IDs and assigning switch ports to different VLANs. It demonstrates the fundamental role of VLANs in modern switched networks.

### 6. Two Switch VLAN
Extending VLANs across multiple switches requires consistent VLAN configuration and trunk links. This setup enables communication between devices in the same VLAN, even if connected to different switches. It highlights the use of trunk ports and VLAN tagging. The experiment emphasizes VLAN scalability and inter-switch communication.

### 7. VLAN with Trunk Link
A trunk link allows multiple VLANs to be carried over a single physical connection between switches. It uses VLAN tagging (e.g., IEEE 802.1Q) to differentiate traffic. This setup is essential when VLANs span multiple switches. It demonstrates efficient network design by minimizing cabling and supporting segmented network architectures.

### 8. DHCP
The Dynamic Host Configuration Protocol automatically assigns IP addresses, subnet masks, gateways, and DNS information to devices on a network. It reduces administrative overhead and ensures no IP conflicts. This experiment covers setting up a DHCP server and observing address leases. DHCP is crucial in both home and enterprise networks for scalable IP management.

### 9. OSPF
Open Shortest Path First (OSPF) is a link-state routing protocol that uses Dijkstra’s algorithm to compute the shortest path. It maintains a topology map of the entire network and updates routing tables dynamically. This experiment includes configuring OSPF on routers and observing automatic route discovery. OSPF is preferred for its scalability and fast convergence.

### 10. IBGP
Internal BGP (iBGP) enables route sharing between routers within the same Autonomous System (AS). Unlike distance-vector protocols, BGP is path-vector and policy-based, focusing on route selection based on attributes. iBGP is used to distribute external routes learned via eBGP to internal routers. It plays a vital role in large-scale and ISP networks.
