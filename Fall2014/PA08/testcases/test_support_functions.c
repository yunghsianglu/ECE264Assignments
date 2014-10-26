
#define TRUE 1
#define FALSE 0

static int strcmp_forward(const char * str_a, const char * str_b)
{
    return strcmp(str_a, str_b);
}

static int strcmp_reverse(const char * str_a, const char * str_b) 
{
    return -strcmp(str_a, str_b);
}

static int strcmp_length(const char * str_a, const char * str_b)
{
    return strlen(str_a) - strlen(str_b);
}

static int strcmp_int(const char * str_a, const char * str_b)
{
    return atoi(str_a) - atoi(str_b);
}

static void List_print(List * list)
{
    List * tail = list;
    while(tail != NULL) {
    	printf("\"%s\" ==> ", tail->str);
    	tail = tail->next;
    }
    printf("NULL");
}

static void print_compar(int (*compar)(const char *, const char *)) 
{
    if(compar == strcmp_forward) printf("return strcmp(a, b)");
    else if(compar == strcmp_reverse) printf("return -strcmp(a, b)");
    else if(compar == strcmp_length) printf("return strlen(a) - strlen(b)");
    else if(compar == strcmp_int) printf("return atoi(a) - atoi(b)");
    else printf("[UNKNOWN]");
}

static List * List_create(const char * * strArr, int len)
{
    if(len == 0)
	return NULL;
    List * ret = List_createNode_sol(strArr[0]);
    ret->next = List_create(++strArr, len - 1);
    return ret;
}

static List * List_clone(List * list)
{
    if(list == NULL) 
	return NULL;
    List * ret = List_createNode_sol(list->str);
    ret->next = List_clone(list->next);
    return ret;
}

static List * make_list(int list_number)
{
    const char * l0[] = { "b", "d", "f" };
    const char * l1[] = { "a", "c", "e", "g", "h", "i", "j" };
    const char * l2[] = { "2", "3", "5", "7" };
    const char * l3[] = { "11", "13", "17", "19", "23" };
    const char * l4[] = { "2010" };
    const char * l5[] = { "Hello", "Doctor", "Name", "Continue", "Yesterday", 
			  "Tomorrow" };
    const char * l6[] = { "sea", "a", "be" };
    const char * l7[] = { "deee" };

    switch(list_number) {
    case 0: return List_create(l0, sizeof(l0) / sizeof(const char *));
    case 1: return List_create(l1, sizeof(l1) / sizeof(const char *));
    case 2: return List_create(l2, sizeof(l2) / sizeof(const char *));
    case 3: return List_create(l3, sizeof(l3) / sizeof(const char *));
    case 4: return List_create(l4, sizeof(l4) / sizeof(const char *));
    case 5: return List_create(l5, sizeof(l5) / sizeof(const char *));
    case 6: return List_create(l6, sizeof(l6) / sizeof(const char *));
    case 7: return List_create(l7, sizeof(l7) / sizeof(const char *));
    }
    return NULL;
}

