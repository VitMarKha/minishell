#include "logic.h"
#include "../parser/parser.h"
#include "../libft/libft.h"

//возвращаем только содержимое переменной
//env - наша копия листа, param - параметр, который мы ищем
char *env_var_param(t_list *env, char *param)
{
	int flag;

	flag = 0;
	while (env)
	{
		if(ft_strncmp(env->content, param, ft_strlen(param)) == 0)
		{
			flag = 1;
			break;
		}
		env = env->next;
	}
	return (flag ? env->content+ft_strlen(param) + 1 : "");
}

//возвращаем всю строку с переменной
char *env_var_full_param(t_list *env, char *param)
{
	int flag;

	flag = 0;
	while (env)
	{
		if(ft_strncmp(env->content, param, ft_strlen(param)) == 0)
		{
			flag = 1;
			break;
		}
		env = env->next;
	}
	if (flag)
		return (env->content);
	return ("");
}

char *change_value_by_key(char *key, char *value)
{
	return (ft_strjoin(key, value));
}

t_list *env_list_pos(t_list *env, char *param)
{
	int flag;

	flag = 0;
	while (env)
	{
		if(ft_strncmp(env->content, param, ft_strlen(param)) == 0)
		{
			flag = 1;
			break;
		}
		env = env->next;
	}
	if (flag)
		return (env);
	return (NULL);
}
