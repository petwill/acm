//Circulation problems
http://www.win.tue.nl/~nikhil/courses/2013/2WO08/scribenotes26febv02.pdf


Flow problems with boundary

1.feasible flow in a network with both upper and lower capacity constraints, no source or sink: 
  capacities are changed to upper bound — lower bound. 
  
  Add a new source and a sink. 
  let M[v] = (sum of lower bounds of ingoing edges to v) — (sum of lower bounds of outgoing edges from v). 
  For all v, 
    if M[v]>0 then add edge (S,v) with capacity M, 
    otherwise add (v,T) with capacity -M. 
   
   Actually, this equals to doing the following steps for every edges
   edges u --> v with lb
   addEdge(s, v, lb) and addEdge( u, t, lb)
   
   If all outgoing edges from S are full, then a feasible flow exists, it is the flow plus the original lower bounds.
   
2.maximum flow in a network with both upper and lower capacity constraints, with source s and sink t : 
  //referenced from the book 挑戰城市競賽acm-icpc and
  //http://web.engr.illinois.edu/~jeffe/teaching/algorithms/2009/notes/18-maxflowext.pdf
  a. add edge (t,s) with capacity infinity. 
  // Binary search for the lower bound, check whether a feasible exists for a network WITHOUT source or sink ??
  
  
  b. add new source and sink, ss and tt
      for all edges u --> v with lb
      addEdge( ss, v, lb) and addEdge( u, tt, lb)
  c. f1 = maxFlow of current graph
  d. if ss -> other verticles aren't all used ==> no feasible solution
  e. addEdge(ss, s, inf), addEdge(t, tt, inf), removeEdge(t, s) (not necessary)
  f. f2 = maxFlow of current graph
  c. final answer will be f2 - the sum of edge demands
  
