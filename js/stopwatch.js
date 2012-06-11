(function($){

  Drupal.behaviors.stopwatch = {
    attach: function(context) { 
      // start & stop
      $('.start_timer').click(function(){
        var index = $(this).attr('index');
        $('.triggervalue[index="'+ index + '"], .split[index="'+ index + '"]').toggle();
        $('.timer[index="'+ index + '"]').stopwatch().stopwatch('toggle');
      });
      
      // register splts
      $('.split').click(function(){
        var index = $(this).attr('index');
        var distance = $('.split-distance:radio:checked').val();
        var field = $('.splittime[index="'+ index + '"]');
        var split = parseInt(field.attr('split'));
        var time = distance * (split + 1) + ' : ' +  $('.timer[index="'+ index + '"]').text();
        var splits = field.html();
        if (split == 0){
          splits = time;
        }
        else {
          splits += "\n" + time;
        }
        field.attr('split', split + 1).html(splits).val(splits);
      })
    }
  }
})(jQuery);
