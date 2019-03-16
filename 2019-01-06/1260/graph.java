import java.util.*;
class Graph{
	class Node{
		int data;
		boolean marked;
		LinkedList <Node> adjacent;
		public Node(int data){
			adjacent = new LinkedList<Node>();
			this.data = data;
			this.marked = false;
		}
	}

	Node[] nodes;
	Queue queue;
	public Graph(int size){
		nodes = new Node[size];
		queue = new LinkedList<Node>();
		for(int i = 0; i < size; i++)
			nodes[i] = new Node(i);
	}

	public void dfsR(int idx){
		dfsR(nodes[idx]);
	}

	public void dfsR(Node node){
		node.makred = true;
		visit(node);
		for(Node n: node.adjacent ){
			if(!n.marked)
				dfsR(n);
		}
	}

	public void bfs(int idx){
		bfs(nodes[idx]);
	}
	
	public void bfs(Node node){
		node.makred = true;
		queue.add(node);
		while(!queue.isEmpty()){
			Node r = queue.remove();
			visit(r);
			for(Node n: r.adjacent){
				if(!n.marked){
					queue.add(n);
					n.marked= true;
				}
			}
		}
	}


	public void visit(Node node){
		System.out.println(node.data);
	}
}