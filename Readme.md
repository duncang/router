# Router

This project demonstrates some basic C unit test coverage.

This project is licensed under the MIT License. See the [LICENSE.md](LICENSE.md) file for details.

# High Level Requirements

- The router system shall consume inputs from an arbitrary interface and route them to a specified output interface.
- Supported physical input interfaces shall include rs232, rs422, and rs485.
- The initial supported output interface shall be an Ethernet TCP socket.
- The interface shall be bidirectional.

# Low Level Requirements

| ID | Requirement | Rationale |
| --- | --- | --- |
| LLR-01 | The software shall define a common interface abstraction for all physical communication endpoints. | This enables the router to operate with different physical transports while keeping the routing logic independent of interface implementation details. |
| LLR-02 | The software shall support RS232, RS422, and RS485 as physical input interfaces. | This satisfies the HLR that the router must accept inputs from the specified serial standards. |
| LLR-03 | Each serial input interface shall be configurable for baud rate, data bits, parity, stop bits, and flow control. | Serial communication requires parameterization to work correctly with attached devices and field conditions. |
| LLR-04 | The initial supported output interface shall be an Ethernet TCP socket. | This satisfies the HLR for the initial network-based output path and establishes the first supported external connection method. |
| LLR-05 | The software shall support configuration of TCP destination address, port, connection timeout, and connection mode. | A generic TCP output must be configurable to match deployment requirements and network topology. |
| LLR-06 | The router shall route data from an arbitrary input interface to a specified output interface using a configurable mapping or routing table. | This directly implements the HLR requirement that input data is consumed and directed to a chosen output. |
| LLR-07 | The software shall support bidirectional operation so that data may flow from input to output and from output to input. | This ensures the router is not limited to one-way forwarding and satisfies the bidirectional requirement. |
| LLR-08 | The software shall provide buffering for ingress and egress traffic to handle interface timing differences and transient stalls. | Routing between interfaces with different timing behavior requires staged data handling to avoid drops and ensure reliability. |
| LLR-09 | The software shall detect and report interface failures, timeouts, disconnects, and communication errors. | A reliable router must expose conditions that could affect data delivery or require operator intervention. |
| LLR-10 | The software shall provide configuration validation and diagnostics for interface selection, route selection, and communication status. | This ensures valid routing configurations are accepted and operational state is visible for debugging and maintenance. |
| LLR-11 | The software shall support non-blocking or asynchronous I/O for interface operations when feasible. | This helps maintain continuous operation and prevents one interface from blocking the processing of others. |
| LLR-12 | The software shall be testable through unit tests and interface-level integration tests using mock or simulated endpoints. | Testability is required to verify compliance with both HLR and LLR objectives without requiring all hardware interfaces in every environment. |

# Low Level Requirements

TBD
