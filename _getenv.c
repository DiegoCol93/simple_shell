#include "holberton.h"

/**
 * _getenv - function that gets the value of a env variable.
 *
 *  Arguments:
 *    @name:    - Pointer to name of env variable.
 *
 *   Return:  - on success, pointer to value of env variable. NULL for fail.
 *
 * |---------------------- Written by Daniel Cortes ----------------------|
 * |-------------------------- and Diego Lopez ---------------------------|
 * |-------------------------- November 14 2020 --------------------------|
 */
char *_getenv(const char *name)
{
	unsigned int i;
	extern char **environ;
	char **argument, *env_value = NULL;
	int equal;

	i = 0;
	while (environ[i] != NULL)
	{
		argument = divide_string(environ[i], "=");
		equal = _strcmp(argument[0], name);
		if (equal == 0)
		{
			env_value = _strdup(argument[1]);
			break;
		}
		else
			free(argument[i]);
		i++;
	}
/*	for(j = 0; argument[j]; j++)
	free(argument[j]);*/
	free(argument);
	return (env_value);
}
/*
/**
 * main - prints the environment using environ.
 *
 * Return: Always 0.
 *
int main(int ac, char **av)
{
	char *name = av[1];
	char *value;

	value = _getenv(name);
	if (value != NULL)
		printf("%s\n", value);
	else
		printf("(null)\n");
	return (0);
}*/
