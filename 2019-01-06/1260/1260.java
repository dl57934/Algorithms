import java.io.*;
import java.util.*;

// class Graph{
// 	class Node{
// 		int data;
// 		LinkedList<Node> adjacent;
// 		boolean marked;
// 		Node(int data){
// 			this.data = data;
// 			this.marked = false;
// 			adjacent = new LinkedList<Node>();
// 		}
// 	}
// 	Node[] nodes;
// 	Graph(int size){
// 		nodes = new Node[size];
// 		for(int i = 1; i < size; i++){
// 			nodes[i] = new Node(i);
// 		}
// 	}
// 	void addEdge(int l1, int l2){
// 		Node n1 = nodes[l1];
// 		Node n2 = nodes[l2];
// 		if(!n1.adjacent.contains(n2))
// 			n1.adjacent.add(n2);
// 		if(!n2.adjacent.contains(n1))
// 			n2.adjacent.add(n1);
// 	}

// 	void dfsR(Node r){
// 		if (r == null) return;
// 		r.marked = true;
// 		visit(r);
// 		for(Node n : r.adjacent){
// 			if(!n.marked)
// 				dfsR(n);
// 		}
// 	}

// 	void visit(Node n){
// 		System.out.print(n.data+" ");
// 	}

// 	void dfsR(int idx){
// 		Node R = nodes[idx];
// 		dfsR(R);
// 	}
// }

class Graph{
	class Node{
		int data;
		LinkedList<Node> adjacent;
		boolean visit;
		Node(int data){
			this.adjacent = new LinkedList<Node>();
			this.data = data;
			this.visit =false;
		}
	}
	Node []nodes;

	public Graph(int size){
		nodes = new Node[size];
		for(int i = 1; i < size; i++){
			nodes[i] = new Node(i);
		}
	}

	public void addEdge(int l1, int l2){
		Node n1 = nodes[l1];
		Node n2 = nodes[l2];
		if(!n1.adjacent.contains(n2))
			n1.adjacent.add(n2);
		if(!n2.adjacent.contains(n1))
			n2.adjacent.add(n1);
	}

	public void dfsR(int i){
		dfsR(nodes[i]);
	}

	public void dfsR(Node node){
		if(node == null) return;
		node.visit =true;
		visit(node);
		for(Node n: node.adjacent){
			if(!n.visit)
				dfsR(n);
		}

	}

	public void visit(Node node){
		System.out.print(node.data+" ");
	}
}


class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String[] line = bfr.readLine().split(" ");
		int size = strToInt(line[0]);
		int trunkSize = strToInt(line[1]);
		int startPoint = strToInt(line[2]);
		Graph graph = new Graph(size+1);
		for(int i = 0; i < trunkSize; i++){
			String[] thrunk = bfr.readLine().split(" ");
			int start = strToInt(thrunk[0]);
			int end = strToInt(thrunk[1]);
			graph.addEdge(start, end);
		}
		graph.dfsR(startPoint);
	} 

	private static int strToInt(String line){
		return Integer.parseInt(line);
	}
}













