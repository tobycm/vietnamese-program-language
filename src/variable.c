// #include "string.util.c"
struct Map
{
    char *key;
    char *value;
    int *IntValue;
    struct Map *next;
};

struct Map *head = NULL;

char *getVariableValue(char *name)
{
    struct Map *item = head;
    if (CompareString(trimString(name), ""))
    {
        printf("cannot get var with name is [%s] \n", name);
        exit(1);
    }
    while (item)
    {
        if (CompareString(item->key, trimString(name)))
        {
            return item->value;
        }
        item = item->next;
    }
    return NULL;
}

struct Map *getVariable(char *name)
{
    struct Map *item = head;
    if (CompareString(trimString(name), ""))
    {
        printf("cannot get var with name is [%s] \n", name);
        exit(1);
    }
    while (item)
    {
        if (CompareString(item->key, trimString(name)))
        {
            return item;
        }
        item = item->next;
    }
    return NULL;
}

bool setVariable(char *name, char *value)
{
    if (CompareString(trimString(name), ""))
    {
        printf("cannot set var with name is [%s] \n", name);
        exit(1);
    }
    if (CompareString(trimString(value), ""))
    {
        printf("cannot set var with value is [%s] \n", value);
        exit(1);
    }
    struct Map *item = head;
    while (item)
    {
        if (CompareString(item->key, trimString(name)))
        {
            item->value = trimString(value);
            item->IntValue = isNumber(value) ? (int *)(trimString(value)) : NULL;
            return true;
        }
        item = item->next;
    }
    return false;
}

void newVariable(char *name, char *value)
{
    struct Map *newConfig = (struct Map *)malloc(sizeof(struct Map));
    if (CompareString(trimString(name), ""))
    {
        printf("cannot declare var with name is [%s] \n", name);
        exit(1);
    }
    if (CompareString(trimString(value), ""))
    {
        printf("cannot declare var with value is [%s] \n", value);
        exit(1);
    }
    if (getVariableValue(name) != NULL)
    {
        printf("var [%s] was declare", name);
        exit(1);
    }
    newConfig->key = trimString(name);
    newConfig->value = trimString(value);
    newConfig->next = head;
    newConfig->IntValue = isNumber(value) ? (int *)value : NULL;
    head = newConfig;
}
