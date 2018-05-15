#include <lua.h>
#include <lauxlib.h>

static int l_find(lua_State *L) {
  const char *ip= luaL_checkstring(L, 1);
  char result[500] = {0};
  if (ip == NULL) {
    return 0;
  }
  strcpy(result, "test find ip ");
  strcat(result, ip);
  lua_pushstring(L, result);
  return 1;
}

static int l_init(lua_State *L) {
  const char *data= luaL_checkstring(L, 1);
  if (data == NULL) {
    return 0;
  }
  printf("init.data=%s\n", data);
  return 1;
}

static const struct luaL_Reg funcs[] = {
  {"test_find", l_find},
  {"test_init", l_init},
  {NULL, NULL}
};

int luaopen_libluatest(lua_State *L) {
  luaL_register(L, "libluatest", funcs);
  return 1;
}
