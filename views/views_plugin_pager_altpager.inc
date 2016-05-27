<?php

/**
 * @file
 * The plugin to handle Altpager.
 *
 * @ingroup views_pager_plugins
 */
class views_plugin_pager_altpager extends views_plugin_pager_mini {

  /**
   * Summary title overwrite.
   */
  function summary_title() {

    $quantity = 10;
    if(isset($this->options['quantity'])) {
      $quantity = $this->options['quantity'];
    }

    $step = 10;
    if(isset($this->options['step'])) {
      $step = $this->options['step'];
    }

    $pages = 10;
    if(isset($this->options['pages'])) {
      $pages = $this->options['pages'];
    }

    return t('Altpage, Start with !quantity, step !step and !pages pages max', array ('!quantity' => $quantity, '!step' => $step, '!pages' => $pages));
  }

  /**
   * Query overwrite.
   */
  function query() {
    // Override query.
  }

  /**
   * Pre execute overwrite.
   */
  function pre_execute(&$query) {

    // Count all entries.
    $max_count = $query
      ->countQuery()
      ->execute()
      ->fetchField();

    $quantity = 10;
    if(isset($this->options['quantity'])) {
      $quantity = $this->options['quantity'];
    }

    $step = 10;
    if(isset($this->options['step'])) {
      $step = $this->options['step'];
    }

    $pages = 10;
    if(isset($this->options['pages'])) {
      $pages = $this->options['pages'];
    }

    if($max_count > $quantity) {
      $pager_steps = array();
      $pager_steps[$quantity] = $quantity;

      $page_count = $quantity;
      while($pages > 0) {
        $pages--;
        if( $page_count + $step > $max_count) {
          break;
        }
        $page_count = $page_count + $step;
        $pager_steps[$page_count] = $page_count;
      }
      altpager_items_elements($pager_steps);
    }

    // Save data count all entries.
    altpager_count_all_items($max_count);


    // Count viewed.
    $count_items = altpager_count_items_viewed();

    // Apply limit.
    $query->range(0, $count_items);
  }

  /**
   * Options definition overwrite.
   */
  function option_definition() {
    return array(
      'quantity' => 10,
      'step' => 10,
      'pages' => 5,
    );
  }

  /**
   * Options form overwrite.
   */
  function options_form(&$form, &$form_state) {
    $form['quantity'] = array(
      '#type' => 'textfield',
      '#title' => t('Items on first page'),
      '#description' => t('How many items display on first page.'),
      '#default_value' => $this->handler->options['quantity'],
    );
    $form['step'] = array(
      '#type' => 'textfield',
      '#title' => t('Page step'),
      '#description' => t('How many items display on each step.'),
      '#default_value' => $this->handler->options['step'],
    );
    $form['pages'] = array(
      '#type' => 'textfield',
      '#title' => t('Pages'),
      '#description' => t('How many pages to generate.'),
      '#default_value' => $this->handler->options['pages'],
    );
  }

  /**
   * Options form validate overwrite.
   */
  function options_validate(&$form, &$form_state) {
    // Disable validate.
  }

  /**
   * Render overwrite.
   */
  function render($input) {
    $pager_theme = views_theme_functions('altpager', $this->view, $this->display);

    return theme($pager_theme, array(
      'element' => $this->options,
    ));
  }

}
