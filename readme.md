# Architecture, Model and Analysis of CPS (AMA-CPS)
Project on Modelling and Analysis
<img width="805" alt="1" src="https://github.com/MeIbtihajnaeem/AMA-CPS-Project-on-Modelling-and-Analysis/assets/55640263/2d1b2385-f115-460e-b162-dcb9d7f0ddb3">


## Introduction

### System Specification
The system is defined through the Reliability
<img width="396" alt="2" src="https://github.com/MeIbtihajnaeem/AMA-CPS-Project-on-Modelling-and-Analysis/assets/55640263/3073a3d5-ed25-47b9-b3a2-af411117d3fd">

Block Diagram shown in the picture.
1. The system fails if there is no path between s and d, otherwise it is working. While the system is failed (not working), the units cannot fail (they are not operational). Unit A has a constant (negative exponential) failure-rate equal to 𝜆/4, and it is repaired with a constant (negative exponential) rate equal to μ/4;
2. Each unit B i, with 1≤𝑖𝑖≤2, fails with a constant (negative exponential) rate equal to 𝜆/2, and it is repaired with a constant (negative exponential) rate equal to μ/2;
3. Each unit Ci, with 1≤𝑖𝑖≤3, fails with a constant (negative exponential) rate equal to 𝜆, and it is repaired with a constant (negative exponential) rate equal to μ.

#### Scenarios (System Configurations)
1. (Option R1): the units cannot be repaired until the whole system fails (i.e., there is no path between s and d).
2. Option (O3): repairs can be carried out in parallel (more units under repair at the same time), with no restrictions on the order of repairs.
3. Option (W2): the failed system re-starts working only if all the failed units have been repaired.

## Description
### Atomic
Initially, we have three states: PlaceA, PlaceB, and PlaceC, corresponding to Unit A, B, and C respectively. Specifically, PlaceA contains one token, PlaceB contains two tokens, and PlaceC contains three tokens.
We observe the input gates that enable the occurrence of failure activities by verifying that there are no tokens in the FailState, as mentioned in option W2.
If PlaceA Enables the FailureA activity it will add a token FailState and Fail_Counter, causing the entire system to fail with the failure rate of 𝜆/4.
For PlaceB and PlaceC, there exists a state called FailBC, which stores the Fail token and fail tokens are also added in Fail_Counter with the failure rate of 𝜆/2 and 𝜆 respectively. The FailureBCGate checks if the FailBC state contains five tokens (representing the failure of all five units of B and C). If this condition is true, it adds a token to FailState and resets the FailBC state to zero and causing the entire system to fail.
Whenever the system fails for the first time, a token is added to FirstFailure and remains there indefinitely, without being removed.
As stated in option R1, when there is a token in FailState, the entire system fails and the repair process can begin.
In the repair process, we observe three inputs: RepairA_Input, RepairB_Input, and RepairC_Input.
RepairA_Input:
Condition is if PlaceA has zero tokens, while FailState has tokens greater than zero, and Fail_Counter also has tokens greater than zero. In this case, a token is removed from Fail_Counter.
RepairB_Input:
Condition is if PlaceB has less than 2 tokens, while FailState has tokens greater than zero, and Fail_Counter also has tokens greater than zero. In this case, a token is removed from Fail_Counter.
RepairC_Input:
Condition is if PlaceC has less than 3 tokens, while FailState has tokens greater than zero, and Fail_Counter also has tokens greater than zero. In this case, a token is removed from Fail_Counter.
These gates activate their respective activities Activity_Repair_A, Activity_Repair_B and Activity_Repair_C with repair rate of (μ/4) and (2 - PlaceB -> Mark ()) * (μ/2) and (3- PlaceC -> Mark ()) * μ respectively.
Lastly, we have an output gate called "FailureRepair" which restarts the system by changing FailBC and Failstate to zero. This is done after checking the condition that Fail_Counter has no tokens which means all the failed units have been repaired. The restart involves setting the following values:
FailState = 0, FailBC =0.

<img width="731" alt="3" src="https://github.com/MeIbtihajnaeem/AMA-CPS-Project-on-Modelling-and-Analysis/assets/55640263/09c6c6b6-c92c-4aaa-a9fe-b90f101a7868">

### Reward: Availability
We can find the availability in our case when systems fail one token is added to place FailState which mean the system is not available. So, we can say in Rate Rewards tab of our project Reward:
return (1 - (proSan->FailState -> Mark()));

<img width="574" alt="4" src="https://github.com/MeIbtihajnaeem/AMA-CPS-Project-on-Modelling-and-Analysis/assets/55640263/61724666-e709-4b21-9930-c7a9aa4d5a97">

### Reliability
If there is token in FirstFailure it means the system is no longer Reliable. So, we can say in Rate Rewards tab of our project Reward:
return(1 - (proSan->FirstFailure -> Mark()));
And time type will be instant of time
t = 1, 15, 45, 105, 225, 465 days.

<img width="574" alt="5" src="https://github.com/MeIbtihajnaeem/AMA-CPS-Project-on-Modelling-and-Analysis/assets/55640263/bd4686f1-eb02-4b1d-abdd-2f6323f2ea17">


## Study
As we know we have three Experiment
The metrics can be computed at varying of the following parameters:
• 𝜆 = (10−1, 10−2, 10−3) failures per hour;
• μ = (10−1, 10−2, 10−3) repairs per hour;

<img width="574" alt="6" src="https://github.com/MeIbtihajnaeem/AMA-CPS-Project-on-Modelling-and-Analysis/assets/55640263/3c46dd11-b72f-4c01-85ec-5c93e9f028b8">


### Transformer
A state space consisting of 88 states is generated for analysis.

### Solver
We have two solvers Directed Steady Solver for accuracy reward and Transient Solver for reliability. And we can see their values in project solver files.
You can see the trends below:

<img width="424" alt="7" src="https://github.com/MeIbtihajnaeem/AMA-CPS-Project-on-Modelling-and-Analysis/assets/55640263/c0fd2e79-28e9-4afb-ad64-c552f38a6388">


## Conclusion
To summarize the trends, as the time (days) increases, there is a noticeable decline in reliability and consistency in availability. Moreover, we observe an increase in reliability when the failure rate is reduced, but once the failure rate is 0.1 after 225 days, reliability drops to very small value almost equal to zero. In terms of availability, reducing or increasing the repair rate does not result in a decrease in the system's overall availability hence it is consistent for all the given rates.


