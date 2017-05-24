import xml.etree.ElementTree as ET
import sys

def list_to_string(desc):
  string = ''
  for i in range(len(desc)):
    if i != len(desc) - 1 and desc[i] != '#':
      string = string + desc[i] + ';'
    else:
      string = string + desc[i]
  return string

def print_description(prj_summ):
  desc = []
  desc.append('#')
  
  for child in prj_summ:
    desc.append(child.tag)
  
  print list_to_string(desc)

def process_project_summary(prj_summ):
  output = []
  
  for child in prj_summ:
    output.append(child.attrib['value'])
  
  print list_to_string(output)
  
def process_procedural_summary(proc_summ):
  #print 'proc_summ'
  for child in proc_summ:
    print child

def parse():
  tree = ET.parse(sys.stdin)
  root = tree.getroot()
  for child in root:
    if child.tag == 'project_summary':
      process_project_summary(child)
    #if child.tag == 'procedural_summary':
    #  process_procedural_summary(child)        
    
#tree = ET.parse(sys.stdin)
#root = tree.getroot()
#nodes = [child for child in root]
#print nodes[1]
#print_description(nodes[1])
parse()
