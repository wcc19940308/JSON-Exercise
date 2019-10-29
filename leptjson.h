//
// Created by Administrator on 2019-10-28.
//

#ifndef JSON_EXERCISE_LEPTJSON_H
#define JSON_EXERCISE_LEPTJSON_H

/**
JSON-text = ws value ws
ws = *(%x20 / %x09 / %x0A / %x0D) 关于空白的定义
value = null / false / true
null  = "null"
false = "false"
true  = "true"
 */
typedef enum {
    LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT
} lept_type;

typedef struct {
    lept_type type;
} lept_value;

// 解析json,对json字符串进行json树的解析,v由调用方传入
int lept_parse(lept_value *v, const char *json);

// 解析json的返回值
enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE, // JSON只含有空白'\0'
    LEPT_PARSE_INVALID_VALUE, //
    LEPT_PARSE_ROOT_NOT_SINGULAR // 若JSON在一个值之后，再加上一个空白之后还有其他字符
};

lept_type lept_get_type(const lept_value *v);

#endif //JSON_EXERCISE_LEPTJSON_H
