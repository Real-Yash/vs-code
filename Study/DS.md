
### Stacks

#### Fundamentals of Stack
A stack is a linear data structure that follows the Last In, First Out (LIFO) principle. This means the last element added to the stack is the first one to be removed. Think of it like a stack of plates: you add to the top and remove from the top.

#### Representation and Implementation of Stack Using Arrays
To implement a stack using an array:
1. **Initialize an array** to represent the stack.
2. **Use the end of the array** to represent the top of the stack.
3. Implement the following operations:
   - **Push**: Add an element to the top of the stack.
   - **Pop**: Remove the top element from the stack.
   - **Peek**: Return the top element without removing it.
   - **isEmpty**: Check if the stack is empty.
   - **isFull**: Check if the stack is full (for fixed-size arrays).

#### Applications of Stack
1. **Decimal to Binary Conversion**: Repeatedly divide the decimal number by 2 and push the remainders onto the stack. Pop the elements to get the binary representation.


     ### Decimal to Binary Conversion Using a Stack

        #### Steps:
        1. **Initialize an empty stack**.
        2. **Divide the decimal number by 2** and record the remainder.
        3. **Push the remainder onto the stack**.
        4. **Update the decimal number** to be the quotient of the division.
        5. **Repeat steps 2-4** until the decimal number becomes 0.
        6. **Pop all elements from the stack** to get the binary representation.

    #### Example:
        Let's convert the decimal number 13 to binary.

        1. **Initialize an empty stack**.

        2. **Divide 13 by 2**:
           - Quotient: 6
           - Remainder: 1
           - Push 1 onto the stack.

        3. **Divide 6 by 2**:
           - Quotient: 3
           - Remainder: 0
           - Push 0 onto the stack.

        4. **Divide 3 by 2**:
           - Quotient: 1
           - Remainder: 1
           - Push 1 onto the stack.

        5. **Divide 1 by 2**:
           - Quotient: 0
           - Remainder: 1
           - Push 1 onto the stack.

        6. **The stack now contains**: [1, 1, 0, 1]

        7. **Pop all elements from the stack**:
           - Pop 1 → Binary: 1
           - Pop 1 → Binary: 11
           - Pop 0 → Binary: 110
           - Pop 1 → Binary: 1101

        So, the binary representation of 13 is **1101**.

    #### Code Implementation in Python:
        Here's a simple Python code to demonstrate this process:

        ```python
        def decimal_to_binary(decimal_number):
            stack = []

            while decimal_number > 0:
                remainder = decimal_number % 2
                stack.append(remainder)
                decimal_number = decimal_number // 2

            binary_number = ""
            while stack:
                binary_number += str(stack.pop())

            return binary_number

        # Example usage
        decimal_number = 13
        print(f"The binary representation of {decimal_number} is {decimal_to_binary(decimal_number)}")
        ```

    This code initializes an empty stack, repeatedly divides the decimal number by 2, pushes the remainders onto the stack, and finally pops the elements to form the binary number.




2. **Reversing a String**: Push each character of the string onto the stack and then pop them to get the reversed string.
    

    ### Reversing a String Using a Stack

    #### Steps:
       1. **Initialize an empty stack**.
       2. **Push each character of the string onto the stack**.
       3. **Pop each character from the stack** to form the reversed string.

    #### Example:
        Let's reverse the string "hello".

    1. **Initialize an empty stack**.

    2. **Push each character onto the stack**:
       - Push 'h' → Stack: ['h']
       - Push 'e' → Stack: ['h', 'e']
       - Push 'l' → Stack: ['h', 'e', 'l']
       - Push 'l' → Stack: ['h', 'e', 'l', 'l']
       - Push 'o' → Stack: ['h', 'e', 'l', 'l', 'o']

    3. **Pop each character from the stack**:
       - Pop 'o' → Reversed string: "o"
       - Pop 'l' → Reversed string: "ol"
       - Pop 'l' → Reversed string: "oll"
       - Pop 'e' → Reversed string: "olle"
       - Pop 'h' → Reversed string: "olleh"

    So, the reversed string of "hello" is **"olleh"**.

    #### Code Implementation in Python:
    Here's a simple Python code to demonstrate this process:

    ```python
    def reverse_string(input_string):
        stack = []

        # Push all characters of the string onto the stack
        for char in input_string:
            stack.append(char)

        reversed_string = ""
        # Pop all characters from the stack to form the reversed string
        while stack:
            reversed_string += stack.pop()

        return reversed_string

    # Example usage
    input_string = "hello"
    print(f"The reversed string of '{input_string}' is '{reverse_string(input_string)}'")
    ```

    This code initializes an empty stack, pushes each character of the input string onto the stack, and then pops each character to form the reversed string.

    

3. **Parsing Well-formed Parentheses**: Use a stack to ensure every opening parenthesis has a corresponding closing parenthesis.
    
    ### Parsing Well-formed Parentheses Using a Stack

    #### Steps:
    1. **Initialize an empty stack**.
    2. **Iterate through each character** in the string.
    3. **Push each opening parenthesis** ('(', '{', '[') onto the stack.
    4. **For each closing parenthesis** (')', '}', ']'):
       - Check if the stack is empty. If it is, the string is not well-formed.
       - Pop the top element from the stack.
       - Check if the popped element matches the corresponding opening parenthesis. If it doesn't, the string is not well-formed.
    5. **After iterating through the string**, check if the stack is empty. If it is, the string is well-formed; otherwise, it is not.

    #### Example:
    Let's check if the string "{[()()]}" is well-formed.

    6. **Initialize an empty stack**.

    7. **Iterate through each character**:
       - '{' → Push onto stack → Stack: ['{']
       - '[' → Push onto stack → Stack: ['{', '[']
       - '(' → Push onto stack → Stack: ['{', '[', '(']
       - ')' → Pop from stack (matches '(') → Stack: ['{', '[']
       - '(' → Push onto stack → Stack: ['{', '[', '(']
       - ')' → Pop from stack (matches '(') → Stack: ['{', '[']
       - ']' → Pop from stack (matches '[') → Stack: ['{']
       - '}' → Pop from stack (matches '{') → Stack: []

    8. **Check if the stack is empty**. It is, so the string is well-formed.

    #### Code Implementation in Python:
    Here's a simple Python code to demonstrate this process:

    ```python
    def is_well_formed_parentheses(s):
        stack = []
        matching_parentheses = {')': '(', '}': '{', ']': '['}

        for char in s:
            if char in matching_parentheses.values():
                stack.append(char)
            elif char in matching_parentheses.keys():
                if stack == [] or matching_parentheses[char] != stack.pop():
                    return False
            else:
                continue
            
        return stack == []

    # Example usage
    input_string = "{[()()]}"
    print(f"The string '{input_string}' is well-formed: {is_well_formed_parentheses(input_string)}")
    ```

    This code initializes an empty stack, iterates through each character of the input string, and uses the stack to ensure every opening parenthesis has a corresponding closing parenthesis.


4. **Expression Conversions and Evaluation**: Convert infix expressions to postfix or prefix using stacks and evaluate postfix expressions.

    ### Infix, Postfix, and Prefix Expressions

    - **Infix Expression**: Operators are between operands (e.g., `A + B`).
    - **Postfix Expression**: Operators are after operands (e.g., `A B +`).
    - **Prefix Expression**: Operators are before operands (e.g., `+ A B`).

    ### Converting Infix to Postfix

    #### Steps:
    1. **Initialize an empty stack** for operators and an empty list for the output.
    2. **Iterate through each character** in the infix expression.
    3. **If the character is an operand**, add it to the output list.
    4. **If the character is an operator**:
       - Pop from the stack to the output list until the stack is empty or the top of the stack has an operator of lower precedence.
       - Push the current operator onto the stack.
    5. **If the character is an opening parenthesis** `(`, push it onto the stack.
    6. **If the character is a closing parenthesis** `)`, pop from the stack to the output list until an opening parenthesis is encountered.
    7. **Pop any remaining operators** from the stack to the output list.

    #### Example:
    Convert `A + B * C` to postfix.

    8. **Initialize**: Stack: [], Output: []
    9. **Read 'A'**: Operand → Output: ['A']
    10. **Read '+'**: Operator → Stack: ['+']
    11. **Read 'B'**: Operand → Output: ['A', 'B']
    12. **Read '*'**: Operator → Stack: ['+', '*']
    13. **Read 'C'**: Operand → Output: ['A', 'B', 'C']
    14. **Pop remaining operators**: Output: ['A', 'B', 'C', '*', '+']

    So, the postfix expression is `A B C * +`.

    ### Converting Infix to Prefix

    #### Steps:
    15. **Reverse the infix expression**.
    16. **Replace '(' with ')'** and vice versa.
    17. **Convert the modified expression** to postfix using the same steps as above.
    18. **Reverse the postfix expression** to get the prefix expression.

    #### Example:
    Convert `A + B * C` to prefix.

    19. **Reverse**: `C * B + A`
    20. **Replace**: No change needed here.
    21. **Convert to postfix**: `C B * A +`
    22. **Reverse**: `+ A * B C`

    So, the prefix expression is `+ A * B C`.

    ### Evaluating Postfix Expressions

    #### Steps:
    23. **Initialize an empty stack**.
    24. **Iterate through each character** in the postfix expression.
    25. **If the character is an operand**, push it onto the stack.
    26. **If the character is an operator**:
       - Pop the top two elements from the stack.
       - Apply the operator to these elements.
       - Push the result back onto the stack.
    27. **The final element** in the stack is the result.

    #### Example:
    Evaluate `5 6 2 + *`.

    28. **Initialize**: Stack: []
    29. **Read '5'**: Operand → Stack: [5]
    30. **Read '6'**: Operand → Stack: [5, 6]
    31. **Read '2'**: Operand → Stack: [5, 6, 2]
    32. **Read '+'**: Operator → Pop 6 and 2, push 8 → Stack: [5, 8]
    33. **Read '*'**: Operator → Pop 5 and 8, push 40 → Stack: [40]

    So, the result is `40`.

    #### Code Implementation in Python:
    Here's a simple Python code to demonstrate these processes:

    ```python
    # Function to convert infix to postfix
    def infix_to_postfix(expression):
        precedence = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}
        stack = []
        output = []

        for char in expression:
            if char.isalnum():
                output.append(char)
            elif char == '(':
                stack.append(char)
            elif char == ')':
                while stack and stack[-1] != '(':
                    output.append(stack.pop())
                stack.pop()
            else:
                while stack and stack[-1] != '(' and precedence[char] <= precedence[stack[-1]]:
                    output.append(stack.pop())
                stack.append(char)

        while stack:
            output.append(stack.pop())

        return ''.join(output)

    # Function to evaluate postfix expression
    def evaluate_postfix(expression):
        stack = []

        for char in expression:
            if char.isdigit():
                stack.append(int(char))
            else:
                b = stack.pop()
                a = stack.pop()
                if char == '+':
                    stack.append(a + b)
                elif char == '-':
                    stack.append(a - b)
                elif char == '*':
                    stack.append(a * b)
                elif char == '/':
                    stack.append(a / b)

        return stack[0]

    # Example usage
    infix_expr = "A+B*C"
    postfix_expr = infix_to_postfix(infix_expr)
    print(f"Infix: {infix_expr} -> Postfix: {postfix_expr}")

    postfix_expr = "562+*"
    result = evaluate_postfix(postfix_expr)
    print(f"Postfix: {postfix_expr} -> Result: {result}")
    ```

    This code includes functions to convert infix expressions to postfix and evaluate postfix expressions. 


### Queues

#### Fundamentals of Queue
A queue is a linear data structure that follows the First In, First Out (FIFO) principle. This means the first element added to the queue is the first one to be removed.

#### Representation and Implementation of Queue Using Arrays
To implement a queue using an array:
1. **Initialize an array** to represent the queue.
2. **Use two pointers** (front and rear) to keep track of the start and end of the queue.
3. Implement the following operations:
   - **Enqueue**: Add an element to the rear of the queue.
   - **Dequeue**: Remove an element from the front of the queue.
   - **isEmpty**: Check if the queue is empty.
   - **isFull**: Check if the queue is full (for fixed-size arrays).

#### Circular Queue
A circular queue is a type of queue where the last position is connected back to the first position to make a circle. This helps in efficiently utilizing the space.

#### Applications of Queue
1. **Josephus Problem**: A theoretical problem related to a certain elimination game.
   

    ### Josephus Problem Using Queues

    #### Problem Statement:
    A group of people stand in a circle, and every \( k \)-th person is eliminated until only one person remains. The task is to determine the position of the last remaining person.

    #### Using a Queue:
    To solve the Josephus Problem using a queue, we can simulate the elimination process by repeatedly rotating the queue.

    #### Steps:
    1. **Initialize a queue** with people numbered from 1 to \( n \).
    2. **Dequeue and enqueue** the first \( k-1 \) people to simulate passing the sword.
    3. **Dequeue the \( k \)-th person** (eliminate them).
    4. **Repeat steps 2 and 3** until only one person remains in the queue.

    #### Example:
    Let's solve the Josephus Problem for \( n = 7 \) people and \( k = 3 \).

    5. **Initialize the queue**: [1, 2, 3, 4, 5, 6, 7]
    6. **Pass the sword** (rotate the queue):
    - Dequeue 1, enqueue 1 → Queue: [2, 3, 4, 5, 6, 7, 1]
    - Dequeue 2, enqueue 2 → Queue: [3, 4, 5, 6, 7, 1, 2]
    1. **Eliminate the 3rd person**:
    - Dequeue 3 → Queue: [4, 5, 6, 7, 1, 2]
    1. **Repeat**:
    - Dequeue 4, enqueue 4 → Queue: [5, 6, 7, 1, 2, 4]
    - Dequeue 5, enqueue 5 → Queue: [6, 7, 1, 2, 4, 5]
    - Dequeue 6 → Queue: [7, 1, 2, 4, 5]
    - Continue this process until one person remains.

    #### Code Implementation in Python:
    Here's a simple Python code to solve the Josephus Problem using a queue:

    ```python
    from collections import deque

    def josephus_queue(n, k):
        queue = deque(range(1, n + 1))
        
        while len(queue) > 1:
            for _ in range(k - 1):
                queue.append(queue.popleft())
            queue.popleft()
        
        return queue[0]

    # Example usage
    n = 7  # Number of people
    k = 3  # Step count for elimination
    last_person = josephus_queue(n, k)
    print(f"The position of the last remaining person is {last_person}")
    ```

    This code uses a deque (double-ended queue) to efficiently rotate the queue and eliminate every \( k \)-th person until only one person remains.

    #### Applications:
    The Josephus Problem has applications in various fields, including:
    - **Computer Science**: Algorithms and data structures.
    - **Game Theory**: Strategy and decision-making.
   - **Cryptography**: Secure communication protocols.


2. **Job Scheduling**: Managing tasks in a multi-tasking environment.
    

    ### Job Scheduling Using Queues

    #### Fundamentals:
    Job scheduling is a critical aspect of managing tasks in a multi-tasking environment, such as operating systems, where multiple jobs (tasks) need to be executed efficiently. Queues are often used to manage these tasks due to their First In, First Out (FIFO) nature.

    #### Types of Job Scheduling:
    1. **First-Come, First-Served (FCFS)**: Jobs are executed in the order they arrive.
    2. **Shortest Job Next (SJN)**: Jobs with the shortest execution time are executed first.
    3. **Priority Scheduling**: Jobs are executed based on their priority.
    4. **Round Robin (RR)**: Each job is given a fixed time slice (quantum) and jobs are cycled through.
    5. **Multilevel Queue Scheduling**: Jobs are divided into multiple queues based on their priority or type.

    #### Using Queues for Job Scheduling:
    Let's focus on the **First-Come, First-Served (FCFS)** and **Round Robin (RR)** scheduling algorithms using queues.

    ### First-Come, First-Served (FCFS)
    In FCFS scheduling, jobs are processed in the order they arrive. This can be easily implemented using a queue.

    #### Steps:
    6. **Initialize an empty queue**.
    7. **Enqueue each job** as it arrives.
    8. **Dequeue and process each job** in the order they were enqueued.

    #### Example:
    Consider jobs arriving in the order: Job1, Job2, Job3.

    9. **Initialize the queue**: []
    10. **Enqueue jobs**: [Job1, Job2, Job3]
    11. **Process jobs**:
       - Dequeue Job1 → Process Job1
       - Dequeue Job2 → Process Job2
       - Dequeue Job3 → Process Job3

    ### Round Robin (RR)
    In Round Robin scheduling, each job is given a fixed time slice (quantum) and jobs are cycled through until they are completed.

    #### Steps:
    12. **Initialize an empty queue**.
    13. **Enqueue each job** as it arrives.
    14. **Dequeue the first job**, process it for a fixed time slice, and if it's not completed, enqueue it back.
    15. **Repeat step 3** until all jobs are completed.

    #### Example:
    Consider jobs arriving in the order: Job1, Job2, Job3 with a time slice of 2 units.

    16. **Initialize the queue**: []
    17. **Enqueue jobs**: [Job1, Job2, Job3]
    18. **Process jobs**:
       - Dequeue Job1 → Process for 2 units → Enqueue Job1 (if not completed)
       - Dequeue Job2 → Process for 2 units → Enqueue Job2 (if not completed)
       - Dequeue Job3 → Process for 2 units → Enqueue Job3 (if not completed)
       - Repeat until all jobs are completed.

    #### Code Implementation in Python:
    Here's a simple Python code to demonstrate FCFS and Round Robin scheduling:

    ```python
    from collections import deque

    # FCFS Scheduling
    def fcfs_scheduling(jobs):
        queue = deque(jobs)
        while queue:
            job = queue.popleft()
            print(f"Processing {job}")

    # Round Robin Scheduling
    def round_robin_scheduling(jobs, time_slice):
        queue = deque(jobs)
        while queue:
            job = queue.popleft()
            print(f"Processing {job} for {time_slice} units")
            # Simulate job processing
            job['time'] -= time_slice
            if job['time'] > 0:
                queue.append(job)

    # Example usage
    jobs_fcfs = ["Job1", "Job2", "Job3"]
    print("FCFS Scheduling:")
    fcfs_scheduling(jobs_fcfs)

    jobs_rr = [{"name": "Job1", "time": 5}, {"name": "Job2", "time": 3}, {"name": "Job3", "time": 6}]
    time_slice = 2
    print("\nRound Robin Scheduling:")
    round_robin_scheduling(jobs_rr, time_slice)
    ```

    This code demonstrates how to implement FCFS and Round Robin scheduling using queues. In FCFS, jobs are processed in the order they arrive, while in Round Robin, jobs are processed in cycles with a fixed time slice.



3. **Queue Simulation**: Simulating real-world queues like customer service lines.
    

    ### Queue Simulation

    #### Fundamentals:
    Queue simulation involves modeling and analyzing the behavior of queues to understand and optimize their performance. This is particularly useful in environments where waiting lines are common, such as customer service centers, banks, hospitals, and airports.

    #### Key Concepts:
    1. **Arrival Rate**: The rate at which customers arrive at the queue.
    2. **Service Rate**: The rate at which customers are served.
    3. **Queue Discipline**: The order in which customers are served (e.g., First In, First Out - FIFO).
    4. **Queue Capacity**: The maximum number of customers that can wait in the queue.
    5. **Number of Servers**: The number of service points available to serve customers.

    ### Simulating a Customer Service Line

    #### Steps:
    6. **Initialize the Queue**: Create a queue to hold customers.
    7. **Simulate Customer Arrivals**: Add customers to the queue based on the arrival rate.
    8. **Simulate Service**: Serve customers based on the service rate and queue discipline.
    9. **Collect Data**: Track metrics such as waiting time, queue length, and service time.
    10. **Analyze Results**: Use the collected data to evaluate and optimize the queue performance.

    #### Example:
    Let's simulate a simple customer service line where customers arrive at a rate of 1 per minute and each customer takes 2 minutes to be served.

    11. **Initialize the Queue**: Start with an empty queue.
    12. **Simulate Customer Arrivals**: Customers arrive every minute.
    13. **Simulate Service**: Each customer is served for 2 minutes.
    14. **Collect Data**: Track the waiting time and queue length.

    #### Code Implementation in Python:
    Here's a simple Python code to simulate a customer service line using a queue:

    ```python
    from collections import deque
    import random

    def simulate_queue(arrival_rate, service_rate, simulation_time):
        queue = deque()
        current_time = 0
        total_waiting_time = 0
        total_customers = 0

        while current_time < simulation_time:
            # Simulate customer arrival
            if random.random() < arrival_rate:
                queue.append(current_time)
                total_customers += 1

            # Simulate service
            if queue and current_time % service_rate == 0:
                arrival_time = queue.popleft()
                waiting_time = current_time - arrival_time
                total_waiting_time += waiting_time

            current_time += 1

        average_waiting_time = total_waiting_time / total_customers if total_customers > 0 else 0
        return average_waiting_time, len(queue)

    # Example usage
    arrival_rate = 1 / 1  # 1 customer per minute
    service_rate = 2  # 2 minutes per customer
    simulation_time = 60  # Simulate for 60 minutes

    average_waiting_time, remaining_customers = simulate_queue(arrival_rate, service_rate, simulation_time)
    print(f"Average waiting time: {average_waiting_time} minutes")
    print(f"Remaining customers in queue: {remaining_customers}")
    ```

    This code simulates a customer service line where customers arrive at a specified rate and are served at a specified rate. It tracks the average waiting time and the number of remaining customers in the queue.

    ### Applications:
    Queue simulation can be applied to various real-world scenarios, such as:
    - **Customer Service Centers**: Optimizing the number of service agents to reduce waiting times.
    - **Hospitals**: Managing patient flow to ensure timely medical care.
    - **Airports**: Streamlining security checks and boarding processes.
    - **Banks**: Improving teller efficiency to handle peak hours.

    By simulating and analyzing queues, organizations can make data-driven decisions to enhance customer satisfaction and operational efficiency¹²³.

4. **Categorizing Data**: Organizing data into different categories.
    

    ### Categorizing Data Using Queues

    #### Fundamentals:
    Categorizing data involves organizing data into different groups or categories based on certain criteria. Queues can be particularly useful in scenarios where data needs to be processed and categorized in a sequential manner.

    #### Steps:
    1. **Initialize Multiple Queues**: Create separate queues for each category.
    2. **Process Data Items**: Iterate through the data items and determine their category.
    3. **Enqueue Data Items**: Add each data item to the appropriate queue based on its category.
    4. **Process Queues**: Once all data items are categorized, process each queue as needed.

    #### Example:
    Let's consider a scenario where we need to categorize customer service requests into three categories: "Technical Support", "Billing", and "General Inquiry".

    5. **Initialize Queues**: Create three queues for each category.
    6. **Process Requests**: Iterate through the list of customer requests and determine their category.
    7. **Enqueue Requests**: Add each request to the appropriate queue.
    8. **Process Queues**: Handle each queue separately based on the category.

    #### Code Implementation in Python:
    Here's a simple Python code to demonstrate categorizing data using queues:

    ```python
    from collections import deque

    def categorize_requests(requests):
        technical_support_queue = deque()
        billing_queue = deque()
        general_inquiry_queue = deque()

        for request in requests:
            if request['category'] == 'Technical Support':
                technical_support_queue.append(request)
            elif request['category'] == 'Billing':
                billing_queue.append(request)
            elif request['category'] == 'General Inquiry':
                general_inquiry_queue.append(request)

        return technical_support_queue, billing_queue, general_inquiry_queue

    # Example usage
    requests = [
        {'id': 1, 'category': 'Technical Support', 'details': 'Issue with software installation'},
        {'id': 2, 'category': 'Billing', 'details': 'Question about invoice'},
        {'id': 3, 'category': 'General Inquiry', 'details': 'General question about services'},
        {'id': 4, 'category': 'Technical Support', 'details': 'Network connectivity issue'},
        {'id': 5, 'category': 'Billing', 'details': 'Payment not processed'}
    ]

    tech_support, billing, general_inquiry = categorize_requests(requests)

    print("Technical Support Queue:", list(tech_support))
    print("Billing Queue:", list(billing))
    print("General Inquiry Queue:", list(general_inquiry))
    ```

    This code categorizes customer service requests into three different queues based on their category. Each queue can then be processed separately.

    ### Applications:
    Categorizing data using queues can be applied to various real-world scenarios, such as:
    - **Customer Service**: Organizing service requests into different categories for efficient handling.
    - **Task Management**: Categorizing tasks based on priority or type.
    - **Data Processing**: Organizing data streams into different categories for parallel processing.
    - **Event Handling**: Categorizing events based on their type for appropriate handling.

    By using queues to categorize data, organizations can streamline their processes, improve efficiency, and ensure that each category is handled appropriately.

    


5. **Doubly Ended Queue (Deque)**: A queue where elements can be added or removed from both ends.


    ### Doubly Ended Queue (Deque)

    #### Fundamentals:
    A Doubly Ended Queue, or Deque (pronounced "deck"), is a data structure that allows insertion and deletion of elements from both ends (front and rear). This makes it more flexible than a standard queue, which only allows operations at one end.

    #### Operations:
    1. **Insert at Front**: Add an element to the front of the deque.
    2. **Insert at Rear**: Add an element to the rear of the deque.
    3. **Delete from Front**: Remove an element from the front of the deque.
    4. **Delete from Rear**: Remove an element from the rear of the deque.
    5. **Peek Front**: Get the front element without removing it.
    6. **Peek Rear**: Get the rear element without removing it.
    7. **isEmpty**: Check if the deque is empty.
    8. **isFull**: Check if the deque is full (for fixed-size deques).

    #### Example:
    Consider a deque with the following operations:
    1. Insert 10 at rear.
    2. Insert 20 at front.
    3. Insert 30 at rear.
    4. Delete from front.
    5. Delete from rear.

    The sequence of operations would look like this:
    1. **Insert 10 at rear**: Deque: [10]
    2. **Insert 20 at front**: Deque: [20, 10]
    3. **Insert 30 at rear**: Deque: [20, 10, 30]
    4. **Delete from front**: Deque: [10, 30]
    5. **Delete from rear**: Deque: [10]

    #### Code Implementation in Python:
    Here's a simple Python code to demonstrate the operations of a deque using the `collections.deque` module:

    ```python
    from collections import deque

    # Initialize a deque
    dq = deque()

    # Insert elements
    dq.append(10)  # Insert at rear
    dq.appendleft(20)  # Insert at front
    dq.append(30)  # Insert at rear

    print("Deque after inserts:", list(dq))

    # Delete elements
    dq.popleft()  # Delete from front
    dq.pop()  # Delete from rear

    print("Deque after deletes:", list(dq))

    # Peek elements
    front = dq[0] if dq else None
    rear = dq[-1] if dq else None

    print("Front element:", front)
    print("Rear element:", rear)
    ```

    This code demonstrates how to perform basic operations on a deque, such as inserting and deleting elements from both ends, and peeking at the front and rear elements.

    ### Applications:
    Deques are versatile and can be used in various scenarios, such as:
    - **Palindrome Checking**: Checking if a string is a palindrome by comparing characters from both ends.
    - **Sliding Window Problems**: Efficiently managing a sliding window of elements in algorithms.
    - **Task Scheduling**: Managing tasks that need to be processed from both ends.
    - **Undo/Redo Operations**: Implementing undo and redo functionality in applications.

    By using deques, you can efficiently manage data that requires operations at both ends, making it a powerful tool in many applications.



6. **Priority Queue**: A queue where each element is associated with a priority and elements are served based on their priority.

    ### Priority Queue

    #### Fundamentals:
        A Priority Queue is a special type of queue where each element is associated with a priority. Elements are served based on their priority rather than their order in the queue. Higher priority elements are dequeued before lower priority ones. If two elements have the same priority, they are served according to their order in the queue (FIFO).

    #### Operations:
    1. **Insert (Enqueue)**: Add an element to the queue with a given priority.
    2. **Remove (Dequeue)**: Remove and return the element with the highest priority.
    3. **Peek**: Return the element with the highest priority without removing it.
    4. **isEmpty**: Check if the priority queue is empty.

    #### Example:
    Consider a priority queue with the following elements and priorities:
        - (Task1, Priority 2)
        - (Task2, Priority 1)
        - (Task3, Priority 3)

    The sequence of operations would look like this:
    5. **Insert (Task1, Priority 2)**: Queue: [(Task1, 2)]
    6. **Insert (Task2, Priority 1)**: Queue: [(Task2, 1), (Task1, 2)]
    7. **Insert (Task3, Priority 3)**: Queue: [(Task3, 3), (Task2, 1), (Task1, 2)]
    8. **Remove**: Dequeue Task3 (highest priority) → Queue: [(Task2, 1), (Task1, 2)]
    9. **Remove**: Dequeue Task1 (next highest priority) → Queue: [(Task2, 1)]

    #### Code Implementation in Python:
    Here's a simple Python code to demonstrate the operations of a priority queue using the `heapq` module:

    ```python
    import heapq

    # Initialize an empty priority queue
    priority_queue = []

    # Insert elements with priorities
    heapq.heappush(priority_queue, (2, 'Task1'))
    heapq.heappush(priority_queue, (1, 'Task2'))
    heapq.heappush(priority_queue, (3, 'Task3'))

    print("Priority Queue after inserts:", priority_queue)

    # Remove elements based on priority
    highest_priority_task = heapq.heappop(priority_queue)
    print("Removed highest priority task:", highest_priority_task)

    next_highest_priority_task = heapq.heappop(priority_queue)
    print("Removed next highest priority task:", next_highest_priority_task)

    print("Priority Queue after removals:", priority_queue)
    ```

    This code demonstrates how to perform basic operations on a priority queue, such as inserting elements with priorities and removing elements based on their priority.

    ### Applications:
    Priority Queues are widely used in various applications, including:
    - **Task Scheduling**: Managing tasks based on their priority in operating systems.
    - **Dijkstra's Algorithm**: Finding the shortest path in a graph.
    - **Huffman Coding**: Building optimal prefix codes for data compression.
    - **Event Simulation**: Managing events in a simulation based on their scheduled times.
    - **Load Balancing**: Distributing tasks to servers based on priority.

    By using priority queues, you can efficiently manage tasks and resources based on their importance, ensuring that critical tasks are handled first.

    Feel free to ask if you have any questions or need further clarification!

#### Multiple Stacks and Multiple Queues
    These involve managing multiple stacks or queues within a single array, often used in complex data structures and algorithms.

(1) Implement Stack using Array - GeeksforGeeks. https://www.geeksforgeeks.org/implement-stack-using-array/.
(2) Stack Data Structure - GeeksforGeeks. https://www.geeksforgeeks.org/stack-data-structure/.
(3) Implementation of Stack Using Array in C - GeeksforGeeks. https://www.geeksforgeeks.org/array-implementation-of-stack-in-c/.
(4) en.wikipedia.org. https://en.wikipedia.org/wiki/Stack_(abstract_data_type).