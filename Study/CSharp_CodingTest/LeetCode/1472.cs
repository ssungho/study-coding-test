public class Design_Browser_History
{
    public class BrowserHistory
    {
        public Node head;
        public Node current;
        public Node tail;

        public BrowserHistory(string homepage, Node head = null, Node tail = null)
        {
            Node current = new Node(homepage);
            this.head = current;
            this.current = current;
            this.tail = current;
        }

        public void Visit(string url)
        {
            Node newNode = new Node(url);
            newNode.prev = current;
            current.next = newNode;
            current = newNode;
            tail = newNode;
        }

        public string Back(int steps)
        {
            for (int i = 0; i < steps; i++)
            {
                current = current.prev;
                if (current == null)
                    current = head;
            }
            return current.val;
        }

        public string Forward(int steps)
        {
            for (int i = 0; i < steps; i++)
            {
                current = current.next;
                if (current == null)
                    current = tail;
            }
            return current.val;
        }
    }

    public class Node
    {
        public string val;
        public Node next;
        public Node prev;

        public Node(string val, Node next = null, Node prev = null)
        {
            this.val = val;
            this.next = next;
            this.prev = prev;
        }
    }
}

