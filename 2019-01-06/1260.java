import java.io.*;
import java.util.*;

class Graph{
	class Node{
		int data;
		LinkedList<Node> adjacent;
		boolean marked;
		public Node(int data){
			this.data = data;
			this.marked = false;
			this.adjacent = new LinkedList<Node>();
		}
	}

	Node[] nodes;

	public Graph(int size){
		this.nodes = new Node[size];
		for(int i = 1; i < size; i++){
			this.nodes[i] = new Node(i);
		}
	}

	public void addEdge(int l1, int l2){
		if(!nodes[l1].adjacent.contains(nodes[l2]))
			nodes[l1].adjacent.add(nodes[l2]);
		if(!nodes[l2].adjacent.contains(nodes[l1]))
			nodes[l2].adjacent.add(nodes[l1]);	
	}

	public void dfsR(int start){
		dfsR(nodes[start]);
	}

	public void dfsR(Node n){
		if(n == null) return ;
		n.marked = true;
		visit(n);
		for(Node node: n.adjacent){
			if(!n.marked)
				dfsR(node);
		}
		
	}

	public void visit(Node n){
		System.out.print(n.data+" ");
	}
}

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String[] order = bfr.readLine().split(" ");
		int N = strToInt(order[0]);
		int M = strToInt(order[1]);
		int V = strToInt(order[2]);
		Graph graph = new Graph(N+1);

		for(int i = 0; i < M; i++){
			String[] lines = bfr.readLine().split(" ");
			int start = strToInt(lines[0]);
			int end = strToInt(lines[1]);
			graph.addEdge(start, end);
		}

		graph.dfsR(V);

	}

	public static int strToInt(String str){
		return Integer.parseInt(str);
	}
}





