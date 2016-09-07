Tarjan can be used to find SCC and BCC( both bi-vertex-connected subgraph and bi-edge-connected subgraph )
// Let's name them vbcc and ebcc

==> 基本上兩個元件(component) 都是　子圖( subgraph )

Difference
    1.割邊不會同時再在兩個邊雙連通元件中, 割點可以在兩個點雙連通元件中
    2.割邊的相鄰點 must belong to different 邊雙連通元件, 但割點的相鄰邊 can belong to the same 點雙連通元件
  
  Since 1. , if把「一個點雙連通分量」看作是「一組邊的集合」 ==> every edge belongs to one unique bcc
             we can do this ==>  belong[ edge_index ] = vbcc_index
             
             But basically, vbcc and ebcc are SUBGRAPH !!
             
             
    p.s.
    A connected undirected graph is called a vertex cactus, if each vertex of this graph belongs to at most one simple cycle.
    A simple cycle in a undirected graph is a sequence of distinct vertices v1, v2, ..., vt (t > 2), such that for any i (1 ≤ i < t) exists an edge between vertices vi and vi + 1, and also exists an edge between vertices v1 and vt.
    
    In this situation, vbcc is the same as ebcc
