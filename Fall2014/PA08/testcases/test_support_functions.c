
#define TRUE 1
#define FALSE 0

static int SparseNode_size(SparseNode * node)
{
    if(node == NULL)
	return 0;
    return 1 + SparseNode_size(node->left) + SparseNode_size(node->right);
}

static void SparseNode_toArrayHelper(SparseNode * node, int ** indices, int ** values)
{
    if(node == NULL) 
	return;
    SparseNode_toArrayHelper(node->left, indices, values);
    **indices = node->index;
    **values = node->value;
    (*indices)++;
    (*values)++;
    SparseNode_toArrayHelper(node->right, indices, values);
}

static int SparseNode_compare(SparseNode * root1, SparseNode * root2)
{
    int len1 = SparseNode_size(root1);
    int * indices1 = malloc(len1 * sizeof(int));
    int * values1 = malloc(len1 * sizeof(int));

    int len2 = SparseNode_size(root2);
    int * indices2 = malloc(len2 * sizeof(int));
    int * values2 = malloc(len2 * sizeof(int));
    
    {
	int * indices_itr = indices1;
	int * values_itr = values1;
	SparseNode_toArrayHelper(root1, &indices_itr, &values_itr);
    }

    {
	int * indices_itr = indices2;
	int * values_itr = values2;
	SparseNode_toArrayHelper(root2, &indices_itr, &values_itr);
    }

    int ret = TRUE;

    if(len1 != len2)
	ret = FALSE;
    
    int ind;
    for(ind = 0; ind < len1 && ret; ++ind) {
	if(indices1[ind] != indices2[ind]) ret = FALSE;
	if(values1[ind] != values2[ind]) ret = FALSE;
    }

    free(indices1); 
    free(indices2);
    free(values1);
    free(values2);

    return ret;
}

static int cmp_array(SparseNode * ans, SparseNode * sol) {
    return SparseNode_compare(ans, sol);
    /* if(ans == NULL && sol == NULL) { */
    /*     return TRUE; */
    /* } */
    /* else if(ans != NULL && sol != NULL) { */
    /*     int sameleft = FALSE; */
    /*     int sameright = FALSE; */
    /*     sameleft = cmp_array(ans->left, sol->left); */
    /*     sameright = cmp_array(ans->right, sol->right); */
    /*     if(sameleft &&  */
    /*             sameright &&  */
    /*             ans->index == sol->index &&  */
    /*             ans->value == sol->value) { */
    /*         return TRUE; */
    /*     } */
    /*     else { */
    /*         return FALSE; */
    /*     } */
    /* } */
    /* else { */
    /*     return FALSE; */
    /* } */
}

static int digits(int x) {
    int num = 0;
    if(x < 0) {
        x = -x;
        num++;
    }
    while(x>=1){
        x = x/10;
        num++;
    }
    return num;
}

static void print_array(SparseNode * array, int len) {
    if(array == NULL) {
        return;
    }
    printf("(%d,%d)",array->index, array->value);
    len += (digits(array->index) + digits(array->value) + 3);
    if(array->right != NULL){
        printf("->");
        print_array(array->right, len+2);
    }
    else {
        printf("\n");
    }
    if(array->left != NULL) {
        int i;
        for(i = 0; i < len; i++) {
            printf(" ");
        }
        printf("->");
        print_array(array->left, len+2);
    }
}

static SparseNode * make_array(int array_number)
{
    int a0[2][4] = { {1,3,0,8}, {5,3,6,4} };
    int a1[2][9] = { {4,2,0,40000,6,30,1,5,4}, {30,22,100,3,5,-7,-30,0,20} };
    int a2[2][7] = { {50,25,75,12,30,60,80}, {4,7,-3,9,80,-7,-30} };
    int a3[2][13] = {
        {30,40,50,60,70,80,90,28,25,22,9,6,0},
        {30,2,3,7,30,80,-70,-300,10,200,22,10,65}
    };
    int a4[2][10] = {
        {20,30,25,8,19,18,17,15,16,6},
        {59,3,100,-3,5,2,7,-3,4,20}
    };
    int a5[2][7] = { {1,10,25,8,4,7,11}, {5,3,3,4,-30,20,-4} };
    int a6[2][6] = { {100,36,0,12,9,120}, {50,33,3,100,-6,4} };
    int a7[2][0] = { {}, {} };

    switch(array_number) {
    case 0: return SparseArray_build_sol(a0[0], a0[1], sizeof(a0[0]) / sizeof(const int));
    case 1: return SparseArray_build_sol(a1[0], a1[1], sizeof(a1[0]) / sizeof(const int));
    case 2: return SparseArray_build_sol(a2[0], a2[1], sizeof(a2[0]) / sizeof(const int));
    case 3: return SparseArray_build_sol(a3[0], a3[1], sizeof(a3[0]) / sizeof(const int));
    case 4: return SparseArray_build_sol(a4[0], a4[1], sizeof(a4[0]) / sizeof(const int));
    case 5: return SparseArray_build_sol(a5[0], a5[1], sizeof(a5[0]) / sizeof(const int));
    case 6: return SparseArray_build_sol(a6[0], a6[1], sizeof(a6[0]) / sizeof(const int));
    case 7: return SparseArray_build_sol(a7[0], a7[1], sizeof(a7[0]) / sizeof(const int));
    }
    return NULL;
}

