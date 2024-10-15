import java.util.*;

class Slip20B {

	public static void usingIterator(LinkedList<String> linkedList) {
		Iterator<String> list = linkedList.iterator();

		while (list.hasNext()) {
			System.out.print(list.next() + " ");
		}
		System.out.println();
	}

	public static void usingListIterator(LinkedList<String> linkedList) {
		ListIterator<String> list = linkedList.listIterator(linkedList.size());

		while (list.hasPrevious()) {
			System.out.print(list.previous() + " ");
		}
	}

	public static void main(String[] args) {
		LinkedList<String> linkedList = new LinkedList<>();
		linkedList.add("CPP");
		linkedList.add("Java");
		linkedList.add("Python");
		linkedList.add("Php");

		System.out.println("List Content using Iterator");
		usingIterator(linkedList);

		System.out.println("List Content in reverse order using ListIterator");
		usingListIterator(linkedList);
	}
}
