# Analyzing-Social-Network-Data

### Overview
This project investigates the communities within a social network. The first part of the project will look degree of separation of the entire network. In the second part, the project looks into friendship paradox.

### Data
The provided UCSD facebook data.
Nodes : 14946; Edges : 886442 


### Warm Up Algorithms
* Get Egonet - Returns a list of friends and connections between them for a given source.
* Strongly Connected Components - Gives groups of strongly connected components from a given graph.

### Easy Question
For a given graph, calculate the average degree of separation for each user.
The algorithm uses a BFS to calculate the distance for a user to all users and the average degree of separation for that user is the average of all that distances. The total average is average of all users. The algorithm users in O (V*(V+E)).
The average degree of separation is 2.


### Hard Question
Friendship paradox is a phenomenon where the number of friends of a person is less than average friends of friends of that person.
For this problem, the algorithm calculates whether average friends of friends are more than given the number of friends of that person.
Out of 14946 people, 13053 suffer from Friendship paradox.
