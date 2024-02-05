# Architecture, Model and Analysis of CPS (AMA-CPS)

## Introduction
The **AMA-CPS** project focuses on the modeling and analysis of a Complex Cyber-Physical System (CPS). This document provides an overview of the system architecture, scenarios, descriptions of system components, and analysis metrics.

![Block Diagram](<image1>)

### System Specification
The system's reliability is defined through a block diagram, as depicted in the provided image. Key points include:
- The system fails if there is no path between the source (s) and destination (d) nodes.
- Units have constant failure rates and repair rates, described by negative exponential distributions.

#### Scenarios (System Configurations)
1. **Option R1**: Units cannot be repaired until the entire system fails.
2. **Option O3**: Repairs can occur in parallel with no restrictions on the order.
3. **Option W2**: The system restarts only when all failed units are repaired.

## Description
### Atomic
The system comprises states representing Units A, B, and C, with associated failure and repair processes. The description outlines the conditions triggering system failure and repair activities for each unit.

#### Repair Process
Repair activities for each unit are triggered based on specific conditions, ensuring the restoration of functionality. A token-based mechanism manages the repair process.

### Reward: Availability
The availability of the system is determined by the presence of tokens in the FailState. A reward function calculates system availability based on the absence of failure tokens.

### Reliability
Reliability is assessed based on the presence of tokens in the FirstFailure state. A reward function computes reliability by considering the absence of initial failure tokens over time.

## Study
The project involves three experiments, with metrics computed at varying failure and repair rates. Parameters include failure rate (𝜆) and repair rate (μ), spanning multiple orders of magnitude.

### Transformer
A state space consisting of 88 states is generated for analysis.

### Solver
Two solvers are employed: the Directed Steady Solver for accuracy reward computation and the Transient Solver for reliability assessment. Solver outputs provide insights into system performance.

![Trends](<image7>)

## Conclusion
Analysis reveals trends indicating a decline in reliability and consistency in availability over time. Reductions in failure rates contribute to improved reliability, while repair rate variations do not significantly affect overall availability.


