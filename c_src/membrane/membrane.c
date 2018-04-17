#include "membrane.h"


ERL_NIF_TERM membrane_util_make_error(ErlNifEnv* env, ERL_NIF_TERM reason) {
  ERL_NIF_TERM tuple[2] = {
    enif_make_atom(env, "error"),
    reason
  };

  return enif_make_tuple_from_array(env, tuple, 2);
}


ERL_NIF_TERM membrane_util_make_ok_tuple(ErlNifEnv* env, ERL_NIF_TERM arg) {
  ERL_NIF_TERM tuple[2] = {
    enif_make_atom(env, "ok"),
    arg
  };

  return enif_make_tuple_from_array(env, tuple, 2);
}


ERL_NIF_TERM membrane_util_make_ok_tuple2(ErlNifEnv* env, ERL_NIF_TERM arg1, ERL_NIF_TERM arg2) {
  ERL_NIF_TERM tuple[3] = {
    enif_make_atom(env, "ok"),
    arg1,
    arg2
  };

  return enif_make_tuple_from_array(env, tuple, 3);
}


ERL_NIF_TERM membrane_util_make_ok(ErlNifEnv* env) {
  return enif_make_atom(env, "ok");
}


ERL_NIF_TERM membrane_util_make_todo(ErlNifEnv* env) {
  return enif_make_atom(env, "todo");
}


ERL_NIF_TERM membrane_util_make_error_args(ErlNifEnv* env, const char* field, const char *description) {
  ERL_NIF_TERM tuple[3] = {
    enif_make_atom(env, "args"),
    enif_make_atom(env, field),
    enif_make_string(env, description, ERL_NIF_LATIN1)
  };

  return membrane_util_make_error(env, enif_make_tuple_from_array(env, tuple, 3));
}


ERL_NIF_TERM membrane_util_make_error_internal(ErlNifEnv* env, const char* reason) {
  ERL_NIF_TERM tuple[3] = {
    enif_make_atom(env, "internal"),
    enif_make_atom(env, reason)
  };

  return membrane_util_make_error(env, enif_make_tuple_from_array(env, tuple, 2));
}
