# ESE224Project
Bank-Queue simulation and implementation.
The goal of this project is to design and develop C ++ code and algorithms to simulate a queue in
a bank, serviced by several tellers. A second goal is to effectively employ object-oriented design
techniques, through appropriate use of classes, data structures and Standard Template Libraries
(STLs). 

An amount of customers (0 to 2) arrrive at each timestep.
Each customer wants to conduct 1, 2 or 3 tasks, either deposit a check, withdraw some cash, or print recent transactions from a list.


A teller takes 1 time step to complete a task. So, if a customer wants to deposit a check,
and withdraw some cash, the total service time is 2 time steps.


The number of customers in the queue gets updated at each time step.


Each arriving customer has an ID, account number, account balance and a list of recent
transactions, as its data members.
