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

	Queue <Node> queue;
	Node[] nodes;

	public Graph(int size){
		this.nodes = new Node[size];
		queue = new LinkedList<Node>();
		for(int i = 1; i < size; i++){
			this.nodes[i] = new Node(i);
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

	public void dfsR(int start){
		dfsR(nodes[start]);
	}

	public void dfsR(Node n){
		if(n == null) return ;
		n.marked = true;
		visit(n);
		for(Node node: n.adjacent){
			if(!node.marked)
				dfsR(node);
		}
	}

	public void bfs(int start){
		bfs(nodes[start]);
	}

	public void bfs(Node root){
		root.marked = true;
		queue.add(root);
		while(!queue.isEmpty()){
			Node node = queue.remove();
			visit(node);
			for(Node n: node.adjacent){
				if(!n.marked){
					queue.add(n);
					n.marked = true;
				}
			}
		}
	}

	public void visit(Node n){
		System.out.print(n.data+" ");
	}

	public void init(){
		for(int i =1; i < nodes.length; i++)
			nodes[i].marked = false;
		System.out.println();
	}
	public void sort(){
		for(int i =1; i < nodes.length; i++)
			Collections.sort(nodes[i].adjacent, new Comparator<Node>(){
				public int compare(Node s1, Node s2){
					if(s1.data > s2.data)
						return 1;
					else 
						return -1;
				}
			});
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
		graph.sort();
		graph.dfsR(V);
		graph.init();
		graph.bfs(V);
	}

	public static int strToInt(String str){
		return Integer.parseInt(str);
	}
}





