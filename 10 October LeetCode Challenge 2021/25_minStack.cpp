class MinStack {
	public:
		stack<int>s;
		multiset<int>m;   

		void push(int val) {//insert elements on both set and stack
			s.push(val); 
			m.insert(val);
		}

		void pop() {//poping elements on both set and stack
			int top = s.top();
			s.pop();
			m.erase(m.find(top)); 
		}

		int top() { //return stack top
			return s.top();
		}

		int getMin() {// return set first element 
			return *m.begin();
		}
    };


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
