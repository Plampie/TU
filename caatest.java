Функция Depth(node):
    ако node е NULL:
        върни 0

    leftDepth  = Depth(node.left)
    rightDepth = Depth(node.right)

    ако leftDepth > rightDepth:
        върни leftDepth + 1
    иначе:
        върни rightDepth + 1
