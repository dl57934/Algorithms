import java.util.*;
import java.io.*;

class Graph{
	Queue<Node> qu = new LinkedList<Node>();
	class Node{
		int data;
		LinkedList<Node> adjacent;
		boolean marked;
		public Node(int data){
			this.data = data;
			adjacent = new LinkedList<Node>();
			marked = false;
		}
	}

	Node[] graph;
	public Graph(int size){
		graph = new Node[size+1];
		for(int i = 1; i <=size; i++)
			graph[i] = new Node(i);
	}

	public void addLine(int start, int end){
		Node point1 = graph[start];
		Node point2 = graph[end];
		if(!point1.adjacent.contains(point2))
			point1.adjacent.add(point2);
		if(!point2.adjacent.contains(point1))
			point2.adjacent.add(point1);
	}	

	public void sort(){
		for(int i = 1; i < graph.length; i++){
			Collections.sort(graph[i].adjacent, new Comparator<Node>(){
				public int compare(Node s1, Node s2){
					if(s1.data > s2.data)
						return 1;
					else
						return -1;
				}
			});
		}
	}

	public void calculate(int start){
		dfs(graph[start]);
		graphInit();
		bfs(graph[start]);
	}

	public void dfs(Node node){
		node.marked = true;
		visit(node);
		for(Node nd: node.adjacent){
			if(!nd.marked)
				dfs(nd);
		}
	}

	public void graphInit(){
		for(int i = 1; i < graph.length; i++)
			graph[i].marked=false;
		System.out.println();
	}

	public void bfs(Node node){
		qu.add(node);
		node.marked=true;
		while(!qu.isEmpty()){
			Node nd = qu.remove();
			visit(nd);
			
			for(Node iterNode:nd.adjacent){
				if(!iterNode.marked){
					qu.add(iterNode);
					iterNode.marked = true;
				}
			}
		}
	}

	public void visit(Node node){
		System.out.print(node.data+" ");
	}
}


class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String[] order = bfr.readLine().split(" ");
		int N = strToInt(order[0]);
		int M = strToInt(order[1]);
		int V = strToInt(order[2]);
		Graph graph = new Graph(N);

		for(int i = 0; i < M; i++){
			String[] point = bfr.readLine().split(" ");
			int start = strToInt(point[0]);
			int end = strToInt(point[1]);
			graph.addLine(start, end);
		}
		graph.sort();
		graph.calculate(V);
	}

	public static int strToInt(String str){
		return Integer.parseInt(str);
	}
}