Alternative Pager
========

Alternative Pager. API for alternative pager. It is alternative view point on
Pager functionality


Example:

```php
<?php

// Is module available?
if (module_exists('altpager')) {

  // Lets select some data.
  $sql = 'SELECT nid FROM {node}';
  $output = '';

  // Generate pager.
  $pagerCountShow = altpager_show($sql);

  // Get total count output.
  $count = altpager_get_count();

  // Let's collect result data.
  $result = db_query_range($sql, array(), 0, $count);
  $output_nodes = '';

  while ($n = db_fetch_object($result)) {
    $n2 = node_load($n->nid);
    $output_nodes .= theme('node', $n2, TRUE, FALSE);
  }//while

  // Output data.
  $output .= $pagerCountShow;
  $output .= '<div class="nodes">';
  $output .= $output_nodes;
  $output .= '</div>';
  $output .= $pagerCountShow;

  echo $output;
}
?>
```

Output is:
![alt tag](http://i61.tinypic.com/wbs7rb.png)
