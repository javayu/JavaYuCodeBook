
namespace CodeLib{
	template <typename T>
	struct Node{
		Node * next;
		T data;
	};

	template <typename T>
	struct LinkedList{
		Node<T> * head;
	};
}
