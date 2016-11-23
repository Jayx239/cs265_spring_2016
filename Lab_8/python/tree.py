class Node:
    def __init__(self, val):
        self.l_child = None
        self.r_child = None
        self.data = val

def binary_insert(root, node):
    if root is None:
        root = node
    else:
        if root.data > node.data:
            if root.l_child is None:
                root.l_child = node
            else:
                binary_insert(root.l_child, node)
        else:
            if root.r_child is None:
                root.r_child = node
            else:
                binary_insert(root.r_child, node)

def in_order_print(root):
    if not root:
        return
    in_order_print(root.l_child)
    print root.data
    in_order_print(root.r_child)

def pre_order_print(root):
    if not root:
        return        
    print root.data
    pre_order_print(root.l_child)
    pre_order_print(root.r_child) 

def post_order_print(root):
    if not root:
        return        
    
    post_order_print(root.l_child)
    post_order_print(root.r_child)   
    print root.data  

def count_nodes(root):
    if not root:
        return 0        
    
    l = count_nodes(root.l_child)
    r = count_nodes(root.r_child)
      
    return l + r + 1 

def compute_depth(root):
    if not root:
        return -1       
    
    l = compute_depth(root.l_child)
    r = compute_depth(root.r_child)

    if(l>r):
    	m = l
    else:
    	m = r

    return m + 1

response = input("Enter an integer: ")
r = Node(response)

while response != 0:
	response = input("Enter an integer: ")
	if response != 0:
		binary_insert(r,Node(response))

print "in order:"
in_order_print(r)

print "pre order:"
pre_order_print(r)

print "Post order:"
print post_order_print(r);

print "tree depth:"
num = compute_depth(r)-1
print "%d" % (num)

print "number of nodes:"
num2 = count_nodes(r)
print "%d" % (num2)
