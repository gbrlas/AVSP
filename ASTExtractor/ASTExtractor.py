import xml.etree.ElementTree as ET
import sys

features = {}

block_tag = "{http://www.srcML.org/srcML/src}block"
class_tag = "{http://www.srcML.org/srcML/src}class"
function_tag = "{http://www.srcML.org/srcML/src}function"
function_decl_tag = "{http://www.srcML.org/srcML/src}function_decl"
param_list_tag = "{http://www.srcML.org/srcML/src}parameter_list"
param_tag = "{http://www.srcML.org/srcML/src}parameter"

private_modifier = "{http://www.srcML.org/srcML/src}private"
protected_modifier = "{http://www.srcML.org/srcML/src}protected"
public_modifier = "{http://www.srcML.org/srcML/src}public"

for_loop_tag = "{http://www.srcML.org/srcML/src}for"
while_loop_tag = "{http://www.srcML.org/srcML/src}while"
do_while_loop_tag = "{http://www.srcML.org/srcML/src}do"

decl_stmt_tag = "{http://www.srcML.org/srcML/src}decl_stmt"
decl_tag = "{http://www.srcML.org/srcML/src}decl"

template_tag = "{http://www.srcML.org/srcML/src}template"

traversable_blocks_with_namespace = [class_tag, \
                                     block_tag, \
                                    function_tag, \
                                    for_loop_tag, \
                                    while_loop_tag, \
                                    do_while_loop_tag, \
                                    template_tag, \
                                     public_modifier, \
                                     private_modifier, \
                                     protected_modifier
                                     ]

class_modifiers = [private_modifier, protected_modifier, public_modifier]

loop_blocks_with_namespace = [for_loop_tag, \
                                while_loop_tag, \
                                do_while_loop_tag
                              ]

def parse(node, height):
    print height
    for child in node:
        print 'child'
        print 'tag', child.tag
        print 'attrib', child.attrib
        if child.tag in traversable_blocks_with_namespace:
            parse(child, height+1)

def get_max_nesting_depth(node, cnt_already):
    max_nesting_depth = cnt_already

    for child in node:
        cur_val = 0
        if child.tag in traversable_blocks_with_namespace:
            if child.tag == block_tag:
                cur_val = get_max_nesting_depth(child, cnt_already+1)
            else :
                cur_val = get_max_nesting_depth(child, cnt_already)
        if cur_val > max_nesting_depth:
            max_nesting_depth= cur_val

    return max_nesting_depth

def get_max_number_of_nested_loops(node, cnt_already):
    max_nested_loops = cnt_already

    for child in node:
        cur_val = 0
        if child.tag in loop_blocks_with_namespace:
            cur_val = get_max_number_of_nested_loops(child, cnt_already+1)
        elif child.tag in traversable_blocks_with_namespace:
            cur_val = get_max_number_of_nested_loops(child, cnt_already)
        if cur_val > max_nested_loops:
            max_nested_loops = cur_val

    return max_nested_loops

def count_parameters(node):
    cnt_params = 0
    for child in node:
        if child.tag == param_tag:
            cnt_params += 1
    return cnt_params

def get_max_parameters_in_declaration(node):

    max_params = 0

    for child in node:
        cur_val = 0
        if child.tag in traversable_blocks_with_namespace:
            cur_val = get_max_parameters_in_declaration(child)
        if child.tag == param_list_tag:
            cur_val = count_parameters(child)
        if cur_val > max_params:
            max_params = cur_val

    return max_params

def get_number_of_classes(node):
    cnt_classes = 0

    for child in node:
        if child.tag in traversable_blocks_with_namespace:
            cnt_classes += get_number_of_classes(child)
        if child.tag == class_tag:
            cnt_classes += 1

    return cnt_classes

def get_number_of_member_functions(level, node):
    cnt_member_funs = 0

    #print 'parent' + ' ' * level, node.tag
    for child in node:
        #print child.tag
        if child.tag in traversable_blocks_with_namespace:
            cnt_member_funs += get_number_of_member_functions(level + 1, child)
        if node != None and node.tag in class_modifiers and (child.tag == function_tag or child.tag == function_decl_tag):
            cnt_member_funs += 1

    return cnt_member_funs

def count_vars(node):
    cnt_vars = 0
    for child in node:
        if child.tag == decl_tag:
            cnt_vars += 1
    return cnt_vars

def get_number_of_member_variables(node):
    cnt_member_vars = 0

    for child in node:
        if child.tag in traversable_blocks_with_namespace:
            cnt_member_vars += get_number_of_member_variables(child)
        if node != None and node.tag in class_modifiers:
            if child.tag == decl_stmt_tag:
                count_decl_stmt_vars = count_vars(child)
                cnt_member_vars += count_decl_stmt_vars

    return cnt_member_vars

def count_functions(node):
    cnt_funs = 0
    for child in node:
        if child.tag == block_tag:
            for c in child:
                if c.tag in class_modifiers:
                    for cc in c:
                        if cc.tag == function_decl_tag or cc.tag == function_tag:
                            cnt_funs += 1
    return cnt_funs


def get_min_fun_per_class(node):
    cnt_member_funs = 150000

    if node.tag == class_tag:
        cnt_member_funs = count_functions(node)

    for child in node:
        if child.tag in traversable_blocks_with_namespace:
            cnt_member_funs = min(get_min_fun_per_class(child), cnt_member_funs)
    return cnt_member_funs

def get_max_fun_per_class(node):
    cnt_member_funs = 0

    if node.tag == class_tag:
        cnt_member_funs = count_functions(node)

    for child in node:
        if child.tag in traversable_blocks_with_namespace:
            cnt_member_funs = max(get_max_fun_per_class(child), cnt_member_funs)
    return cnt_member_funs

import sys
def printf(format, *args):
    sys.stdout.write(format % args)

def start_parse():
    tree = ET.parse(sys.stdin)
    root = tree.getroot()
    cnt_max_nested_loops = get_max_number_of_nested_loops(root, 0)
    cnt_max_params_in_decl = get_max_parameters_in_declaration(root)
    cnt_max_nesting_depth = get_max_nesting_depth(root, 0)
    cnt_classes = get_number_of_classes(root)
    cnt_member_funs = get_number_of_member_functions(0, root)
    cnt_member_vars = get_number_of_member_variables(root)
    cnt_min_member_funs = get_min_fun_per_class(root)
    cnt_max_member_funs = get_max_fun_per_class(root)

    features['max_nested_loops'] = cnt_max_nested_loops
    features['max_params_in_decl'] = cnt_max_params_in_decl
    features['max_nesting_depth'] = cnt_max_nesting_depth
    features['cnt_classes'] = cnt_classes
    features['member_funs'] = cnt_member_funs
    features['member_vars'] = cnt_member_vars
    features['min_member_funs'] = cnt_min_member_funs
    features['max_member_funs'] = cnt_max_member_funs

    import csv
    sorted_keys = features.keys()
    sorted_keys.sort()
    header = sorted_keys
    for i in range(len(header)-1):
      printf("%s;", header[i])
    printf("%s\n", header[len(header)-1])
    #print 'vals', [features[key] for key in sorted_keys]
    for i in range(len(sorted_keys)-1):
      printf("%f;", features[sorted_keys[i]])
    printf("%f\n", features[sorted_keys[len(sorted_keys)-1]])

    #print 'feature count', len(features)


start_parse()
