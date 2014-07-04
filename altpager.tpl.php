<div class="altpager">
  <ul>
    <li class="prefix"><?php print t('Show'); ?></li>
    <?php print $items; ?>
    <li class="sufix"><?php print t('of !total records', array ('!total' => $total)); ?></li>
  </ul>
</div>
