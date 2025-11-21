# Създаваме клас Node, който ще представя един възел в двоично дърво.
class Node:
    def __init__(self, d):
        self.data = d       # Записваме съдържанието (числото) в полето data
        self.left = None    # В началото няма ляво поддърво → затова е None
        self.right = None   # В началото няма дясно поддърво → затова е None

# Инициализираме няколко възела
firstNode = Node(2)
secondNode = Node(3)
thirdNode = Node(4)
fourthNode = Node(5)

"""
След свързване, дървото ще има структура:

             (2)
            /   \
         (3)     (4)
         /
       (5)
"""


# Свързваме възлите
firstNode.left = secondNode     
firstNode.right = thirdNode     
secondNode.left = fourthNode    
