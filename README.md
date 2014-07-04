altpager
========

Alternative Pager. API for alternative pager. It is alternative view point on Pager functionality


Example:

```
<?php

//is module available?
if(module_exists('altpager')){

//lets select some data
  $sql='SELECT nid FROM node';

//generate pager  
  $pagerCountShow=altpager_Show($sql);

//get total count output  
  $count = altpager_getCount();

//let's collect result data  
  $result = db_query_range($sql,array(),0,$count);
  $output_nodes ='';
  while ($n = db_fetch_object($result)) {
    $n2 = node_load($n->nid);
    $output_nodes .= theme('node', $n2, TRUE,FALSE);
  }//while

//output data
  $output .= $pagerCountShow;
  $output .= '<div class="nodes">';
  $output .=  $output_nodes;
  $output .= "</div>";
  $output .= $pagerCountShow;
  
  echo $output;
}
?>
```
