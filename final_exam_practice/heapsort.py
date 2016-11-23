class heapSort:
	
	def swap(self,a,ind1,ind2):
                temp = a[ind1]
                a[ind1] = a[ind2]
                a[ind2] = temp

	def make_heap(self,a,n):
		k = None
		for i in range(1,n-1):
			k=i
			while a[k] > a[(k-1)/2]:
				self.swap(a,k,(k-1)/2)
				k = (k-1)/2
		#for i in range(1,n-1):
		#	print(a[i])
	def restore_heap(self, a, n):
		k = 0;
		for i in range(0,n-1):
			k=i
			while a[k] < a[(2*k)+1] or a[k] < a[(2*k)+2]:
				if(a[(2*k)+1] >  a[(2*k)+2]):
					self.swap(a,k,(2*k)+1)
					k = (2*k)+1
				else:
					self.swap(a,k,(2*k)+2)
					k = (2*k)+2
	def heap_sort(self,a,n):
		self.make_heap(a,n)
		
		for k in range(n-1,1):
			self.swap(a,0,k)
			self.restore_heap(a,k)


hs = heapSort()
a = [1,2,3,4,5,6,7,8,9]
#hs.make_heap(a,9)
hs.heap_sort(a,9)
for i in range(0,9):
	print(a[i])

