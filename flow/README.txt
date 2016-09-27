Flow problems with boundary

1.feasible flow in a network with both upper and lower capacity constraints, no source or sink: 
  capacities are changed to upper bound — lower bound. 
  Add a new source and a sink. let M[v] = (sum of lower bounds of ingoing edges to v) — (sum of lower bounds of outgoing edges from v). 
  For all v, 
    if M[v]>0 then add edge (S,v) with capacity M, 
    otherwise add (v,T) with capacity -M. 
   If all outgoing edges from S are full, then a feasible flow exists, it is the flow plus the original lower bounds.
   
2.maximum flow in a network with both upper and lower capacity constraints, with source s and sink t: 
  add edge (t,s) with capacity infinity. 
  Binary search for the lower bound, check whether a feasible exists for a network WITHOUT source or sink
