Approach
Line by line:

-> Create a reverse priority queue (smallest->largest) of all the costs
-> fill that priority queue with the list of bars (prices)
-> Add a counter variable to keep track of # of bars bought
-> Run a while loop while our balance is greater than 0 and we have not exceeded the number of bars available
-> If the top of our queue is greater than our current balance we can end the loop
   otherwise subtract the price of that bar from our balance and pop the bar off the queue
   incremenet # of purchases by 1
return count