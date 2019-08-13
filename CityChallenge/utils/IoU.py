import numpy as np  

def calculate_IoU(boxA, boxB):
    """
    boxA    -   [botleft_x, botleft_y, topright_x, topright_y]
        shape of rectangle A
    boxB    -   [botleft_x, botleft_y, topright_x, topright_y]
        shape of rectangle B
    ---------------------------
    Return
    IoU     -   int
        Inter over Union
    """
    y_topright = min(boxA[3], boxB[3])
    x_topright = min(boxA[2], boxB[2])
    y_botleft  = max(boxA[1], boxB[1])
    x_botleft  = max(boxA[0], boxB[0])

    inter = max(0, x_topright - x_botleft) * max(0, y_topright - y_botleft)
    S_recA =  max(0, boxA[2] - boxA[0]) * max(0, boxA[3] - boxA[1])
    S_recB =  max(0, boxB[2] - boxB[0]) * max(0, boxB[3] - boxB[1])
    iou = inter / (S_recA + S_recB - inter)
    return iou

if __name__ == '__main__':
    boxA = [0, 1, 3, 2]
    boxB = [1, 0, 2, 3]
    print("IoU=", calculate_IoU(boxA, boxB))
