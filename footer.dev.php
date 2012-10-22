</div>
<div id="footer" class="clear">
	<div class="credits">
		Copyright: <a href="http://paroid.org" title="OK,This is Me!">paroid</a> | Theme: <a href="http://immmmm.com/wordpress-theme-optimus.html" target="_blank" title="Theme modified from Optimus">Optimus</a> | Power: <a href="http://wordpress.org/" target="_blank" title="Powered by WordPress">WordPress</a>
	</div>
<div id="butt">
<a href="javascript:scrollToTop()" class="ieTop" title="Back to Top">&nbsp;</a>
<form method="get" id="searchform2" class="searchform" action="<?php bloginfo('home'); ?>/">
			<div id="search2"><input type="text" x-webkit-speech value="Search...   " name="s" id="s2" size="15" onfocus="this.className='s-on'; this.value = this.value == this.defaultValue ? '' : this.value" onblur="this.className='s-off'; this.value = this.value == '' ? this.defaultValue : this.value" onmouseover="/*this.focus();*/" /></div>
</form></div>
</div>
</div>

<?php wp_footer(); ?>
</div>
</body>

<?php wp_head(); ?>

<script type="text/javascript">
/*Part I Library*/
/*tipTip Library*/
(function($){$.fn.tipTip=function(options){var defaults={activation:"hover",keepAlive:false,maxWidth:"200px",edgeOffset:3,defaultPosition:"bottom",delay:400,fadeIn:200,fadeOut:200,attribute:"title",content:false,enter:function(){},exit:function(){}};var opts=$.extend(defaults,options);if($("#tiptip_holder").length<=0){var tiptip_holder=$('<div id="tiptip_holder" style="max-width:'+opts.maxWidth+';"></div>');var tiptip_content=$('<div id="tiptip_content"></div>');var tiptip_arrow=$('<div id="tiptip_arrow"></div>');$("body").append(tiptip_holder.html(tiptip_content).prepend(tiptip_arrow.html('<div id="tiptip_arrow_inner"></div>')))}else{var tiptip_holder=$("#tiptip_holder");var tiptip_content=$("#tiptip_content");var tiptip_arrow=$("#tiptip_arrow")}return this.each(function(){var org_elem=$(this);if(opts.content){var org_title=opts.content}else{var org_title=org_elem.attr(opts.attribute)}if(org_title!=""){if(!opts.content){org_elem.removeAttr(opts.attribute)}var timeout=false;if(opts.activation=="hover"){org_elem.hover(function(){active_tiptip()},function(){if(!opts.keepAlive){deactive_tiptip()}});if(opts.keepAlive){tiptip_holder.hover(function(){},function(){deactive_tiptip()})}}else if(opts.activation=="focus"){org_elem.focus(function(){active_tiptip()}).blur(function(){deactive_tiptip()})}else if(opts.activation=="click"){org_elem.click(function(){active_tiptip();return false}).hover(function(){},function(){if(!opts.keepAlive){deactive_tiptip()}});if(opts.keepAlive){tiptip_holder.hover(function(){},function(){deactive_tiptip()})}}function active_tiptip(){opts.enter.call(this);tiptip_content.html(org_title);tiptip_holder.hide().removeAttr("class").css("margin","0");tiptip_arrow.removeAttr("style");var top=parseInt(org_elem.offset()['top']);var left=parseInt(org_elem.offset()['left']);var org_width=parseInt(org_elem.outerWidth());var org_height=parseInt(org_elem.outerHeight());var tip_w=tiptip_holder.outerWidth();var tip_h=tiptip_holder.outerHeight();var w_compare=Math.round((org_width-tip_w)/2);var h_compare=Math.round((org_height-tip_h)/2);var marg_left=Math.round(left+w_compare);var marg_top=Math.round(top+org_height+opts.edgeOffset);var t_class="";var arrow_top="";var arrow_left=Math.round(tip_w-12)/2;if(opts.defaultPosition=="bottom"){t_class="_bottom"}else if(opts.defaultPosition=="top"){t_class="_top"}else if(opts.defaultPosition=="left"){t_class="_left"}else if(opts.defaultPosition=="right"){t_class="_right"}var right_compare=(w_compare+left)<parseInt($(window).scrollLeft());var left_compare=(tip_w+left)>parseInt($(window).width());if((right_compare&&w_compare<0)||(t_class=="_right"&&!left_compare)||(t_class=="_left"&&left<(tip_w+opts.edgeOffset+5))){t_class="_right";arrow_top=Math.round(tip_h-13)/2;arrow_left=-12;marg_left=Math.round(left+org_width+opts.edgeOffset);marg_top=Math.round(top+h_compare)}else if((left_compare&&w_compare<0)||(t_class=="_left"&&!right_compare)){t_class="_left";arrow_top=Math.round(tip_h-13)/2;arrow_left=Math.round(tip_w);marg_left=Math.round(left-(tip_w+opts.edgeOffset+5));marg_top=Math.round(top+h_compare)}var top_compare=(top+org_height+opts.edgeOffset+tip_h+8)>parseInt($(window).height()+$(window).scrollTop());var bottom_compare=((top+org_height)-(opts.edgeOffset+tip_h+8))<0;if(top_compare||(t_class=="_bottom"&&top_compare)||(t_class=="_top"&&!bottom_compare)){if(t_class=="_top"||t_class=="_bottom"){t_class="_top"}else{t_class=t_class+"_top"}arrow_top=tip_h;marg_top=Math.round(top-(tip_h+5+opts.edgeOffset))}else if(bottom_compare|(t_class=="_top"&&bottom_compare)||(t_class=="_bottom"&&!top_compare)){if(t_class=="_top"||t_class=="_bottom"){t_class="_bottom"}else{t_class=t_class+"_bottom"}arrow_top=-12;marg_top=Math.round(top+org_height+opts.edgeOffset)}if(t_class=="_right_top"||t_class=="_left_top"){marg_top=marg_top+5}else if(t_class=="_right_bottom"||t_class=="_left_bottom"){marg_top=marg_top-5}if(t_class=="_left_top"||t_class=="_left_bottom"){marg_left=marg_left+5}tiptip_arrow.css({"margin-left":arrow_left+"px","margin-top":arrow_top+"px"});tiptip_holder.css({"margin-left":marg_left+"px","margin-top":marg_top+"px"}).attr("class","tip"+t_class);if(timeout){clearTimeout(timeout)}timeout=setTimeout(function(){tiptip_holder.stop(true,true).fadeIn(opts.fadeIn)},opts.delay)}function deactive_tiptip(){opts.exit.call(this);if(timeout){clearTimeout(timeout)}tiptip_holder.fadeOut(opts.fadeOut)}}})}})(jQuery);
/*jQuery cookie*/
(function ($, document, undefined) { var pluses = /\+/g; function raw(s) { return s; } function decoded(s) { return decodeURIComponent(s.replace(pluses, ' ')); } var config = $.cookie = function (key, value, options) { if (value !== undefined) { options = $.extend({}, config.defaults, options); if (value === null) { options.expires = -1; } if (typeof options.expires === 'number') { var days = options.expires, t = options.expires = new Date(); t.setDate(t.getDate() + days); } value = config.json ? JSON.stringify(value) : String(value); return (document.cookie = [ encodeURIComponent(key), '=', config.raw ? value : encodeURIComponent(value), options.expires ? '; expires=' + options.expires.toUTCString() : '', options.path    ? '; path=' + options.path : '', options.domain  ? '; domain=' + options.domain : '', options.secure  ? '; secure' : '' ].join('')); } var decode = config.raw ? raw : decoded; var cookies = document.cookie.split('; '); for (var i = 0, parts; (parts = cookies[i] && cookies[i].split('=')); i++) { if (decode(parts.shift()) === key) { var cookie = decode(parts.join('=')); return config.json ? JSON.parse(cookie) : cookie; } } return null; }; config.defaults = {}; $.removeCookie = function (key, options) { if ($.cookie(key) !== null) { $.cookie(key, null, options); return true; } return false; }; })(jQuery, document); 
/*Part I End*/
</script>

<?php if( is_singular() ){ ?>
<script type="text/javascript" src="<?php bloginfo('template_url'); ?>/comments-ajax.js"></script>
<script type="text/javascript">
/*Part II Singular Page*/
	/*smlie hidden button*/
	function hid(){
		var sm=document.getElementById("sml");
		if(sm.style.height=='19px'){
			$("#sml").css({'display':'block'}).animate({height:"0px",padding:"0 0 0 12px"},"normal");
		}else{
			$("#sml").css({'display':'block'}).animate({height:"19px",padding:"4px 0 4px 12px"},"normal");
		}
	}
	function bindReply(){
		$(".comment-reply-link").click(function(){
			$('.comment-body').css({'border-left':'none'});
			var comment = $(this).parent().parent().parent();
			comment.css({'border-left':'4px solid #2089cc'});
			$("#cancel-comment-reply-link").text('取消 @'+comment.find('span.name').text());
			$("#cancel-comment-reply-link").click(function(){
				$('.comment-body').css({'border-left':'none'});
			});
		});
		$(".comment-body").hover(function () {
    			$(this).find('.comment-reply-link').addClass("hover");
    				$(this).find('.date').addClass("hover");
			},function () {
    				$(this).find('.comment-reply-link').removeClass("hover");
	    			$(this).find('.date').removeClass("hover");
		 	 }
		);
	}
	jQuery(document).ready(function($){
		$('#comments .comment-body').dblclick(function(){
			var crl=$('#cancel-comment-reply-link');
			if($(this).next('#respond').length > 0) {crl.click();
			}else{$(this).find('.comment-reply-link').click();crl.text("取消 @"+$(this).find('.name').text());}
			return false
		});
		$('#comments .live').live('dblclick',function(){$(this).next().children('a').click()});

		/*form effect*/
		$('input#author').focus(function() {
			$(this).css({'border':'1px solid #3399ff','background':'#fff'});
			$('.comment-form-author span,.comment-form-author label').css({'color':'#2089cc','font-weight':'bold'});
		});
		$('input#author').blur(function() {
			$(this).css({'border':'1px solid #bbb','background':'#f3f3f3'});
			$('.comment-form-author span,.comment-form-author label').css({'color':'#888','font-weight':'normal'});
		});
		$('input#email').focus(function() {
			$(this).css({'border':'1px solid #3399ff','background':'#fff'});
			$('.comment-form-email span,.comment-form-email label').css({'color':'#2089cc','font-weight':'bold'});
		});
		$('input#email').blur(function() {
			$(this).css({'border':'1px solid #bbb','background':'#f3f3f3'});
			$('.comment-form-email span,.comment-form-email label').css({'color':'#888','font-weight':'normal'});
		});
		$('input#url').focus(function() {
			$(this).css({'border':'1px solid #3399ff','background':'#fff'});
			$('.comment-form-url span,.comment-form-url label').css({'color':'#2089cc','font-weight':'bold'});
		});
		$('input#url').blur(function() {
			$(this).css({'border':'1px solid #bbb','background':'#f3f3f3'});
			$('.comment-form-url span,.comment-form-url label').css({'color':'#888','font-weight':'normal'});
		});
		$('#comment').focus(function() {
			$(this).css({'border':'1px solid #3399ff','background':'#fff'});
			$('.comment-form-comment label').css({'color':'#2089cc','font-weight':'bold'});
		});
		$('#comment').blur(function() {
			$(this).css({'border':'1px solid #bbb','background':'#f3f3f3'});
			$('.comment-form-comment label').css({'color':'#888','font-weight':'normal'});
		});
		$("#sml").css({'display':'none','height':'0','padding-left':'12px'});
		$("#smlLoad").css({'display':'none'});
		$(".hidbtn").click(function(){
			if ($("#sml").find("a").length <= 0){	//first Load
				$("#smlLoad").css({'display':'inline'});
	   			$("#sml").load('/photo/sml.span',function(){
				$("#smlLoad").css({'display':'none'});
					hid();
					$("#sml a").tipTip({defaultPosition:"top",delay:300});
			});				
			}else{hid();}	
		});
		bindReply();
	});
/*Part II End*/
</script>
<?php } ?>
<script type="text/javascript">
	/*Google Analysis*/
  	var _gaq = _gaq || [];
  	_gaq.push(['_setAccount', 'UA-33258218-1']);
  	_gaq.push(['_trackPageview']);
  	(function() {
    		var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    		ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    		var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  	})();

/*Part III damn script*/

	/*scroll to top*/
	function scrollToTop() {
		$('html, body').animate({scrollTop:0}, 'slow');
	}
	function sideBarToggle() {
		if($("#content").width()==680){
			$("#header").hide(200);
			$("#wrap,#content").animate({width:'830px'}, 'slow');
			$(".postWrapper, #comments").animate({width:'812px'},'slow');
			//$("#butt").css({'margin-right':'0px'});
			$("object").css({'width':'788px','height':'540px'});
			$(".postContent img[class!=pow]").css({'max-width':'780px'});
			$("embed").attr({width:'788',height:'540'});
			$("p.audioplayer_container object").css({'width':'320px','height':'24px'}).attr({width:'320',height:'24'});
			$("#nav").animate({width:'820px',marginLeft:'-418px'},'slow',function(){
				$(".sideBar").text('<<').css({'left':'612px','-webkit-border-top-left-radius':'12px','-webkit-border-bottom-left-radius':'12px','-moz-border-radius-topleft':'12px','-moz-border-radius-bottomleft': '12px','border-top-left-radius':' 12px','border-bottom-left-radius':' 12px','-webkit-border-top-right-radius':'0','-webkit-border-bottom-right-radius':'0','-moz-border-radius-topright':'0','-moz-border-radius-bottomright': '0','border-top-right-radius':' 0','border-bottom-right-radius':' 0'}).attr({title:'展开边栏'}).tipTip({defaultPosition:"left",delay:300}).blur();		
				$(".ieTop,#search2").css({display:'inline'});
			});	
			$.cookie("layout",'noSideBar', { expires : 7 ,domain:'paroid.org',path: '/' });
			$(".addthis").hover(function(){$("#content").addClass("wide")},function(){$("#content").removeClass("wide")});

		}else{
			$("#content").animate({width:'680px'}, 'slow');
			$("#wrap").animate({width:'960px'}, 'slow');				
			$(".postWrapper, #comments").animate({width:'662px'},'slow');
			//$("#butt").css({'margin-right':'280px'});
			$("object").css({'width':'640px','height':'480px'});
			$(".postContent img[class!=pow]").css({'max-width':'620px'});
			$("embed").attr({width:'640',height:'480'});
			$("p.audioplayer_container object").css({'width':'320px','height':'24px'}).attr({width:'320',height:'24'});
			$("#nav").animate({width:'960px',marginLeft:'-482px'},'slow',function(){
				$("#header").show(200);
				$(".sideBar").text('>>').css({'left':'490px','-webkit-border-top-right-radius':'12px','-webkit-border-bottom-right-radius':'12px','-moz-border-radius-topright':'12px','-moz-border-radius-bottomright': '12px','border-top-right-radius':' 12px','border-bottom-right-radius':' 12px','-webkit-border-top-left-radius':'0','-webkit-border-bottom-left-radius':'0','-moz-border-radius-topleft':'0','-moz-border-radius-bottomleft': '0','border-top-left-radius':' 0','border-bottom-left-radius':' 0'}).attr({title:'收起边栏'}).tipTip({defaultPosition:"right",delay:300}).blur();
				if(!$.browser.msie){
					$(".ieTop").css({display:'none'});
				}
				$("#search2").css({display:'none'});
			});
			$.cookie("layout",null, { expires : 7 ,domain:'paroid.org',path: '/' });
			$(".addthis").unbind("mouseenter").unbind("mouseleave");
		}
	}
	/*document Ready*/
	jQuery(document).ready(function($){	
		if($('.postContent a[rel!=link]:has(img)').length > 0){
			$.getScript("/wp-content/themes/Optimus/slimbox2.js");
		};
		if($.cookie("layout")){
			$("object").css({'width':'788px','height':'540px'});
			$("embed").attr({width:'788',height:'540'});
			$("p.audioplayer_container object").css({'width':'320px','height':'24px'}).attr({width:'320',height:'24'});
			$(".postContent img[class!=pow]").css({'max-width':'780px'});
			$(".sideBar").attr({title:'展开边栏'}).tipTip({defaultPosition:"left",delay:300});	
			$(".addthis").hover(function(){$("#content").addClass("wide")},function(){$("#content").removeClass("wide")});
		}else{
			$("object").css({'width':'640px','height':'480px'});
			$("embed").attr({width:'640',height:'480'});
			$("p.audioplayer_container object").css({'width':'320px','height':'24px'}).attr({width:'320',height:'24'});
			$(".sideBar").tipTip({defaultPosition:"right",delay:300});
		}
		/*tab slide*/
		$('#tab-title span').click(function(){
			$(this).addClass("selected").siblings().removeClass();
			$("#tab-content > div,#tab-content > ul").slideUp('1500').eq($('#tab-title span').index(this)).slideDown('1500');
		});
		/*open in new tab*/
		$('.postContent p a,.postContent h2 a,.postContent .quote a,.comment-head span.name a').attr({ target: "_blank"});
		/*tipTip*/
		$('.comment-head span.name a').attr({title:"外部链接，谨慎点击！"});
		$('.comment-reply-link').attr({title:"回复TA"});
		//$('.more-link').attr({title:"继续阅读"});
		$('input#author').attr({title:"Your Name [required]"});
		$('input#email').attr({title:"Your Email [required]"});
		$('input#url').attr({title:"Your Website [optional]"});
		$(".quote a[title],.download[title],.comment-reply-link,#most-view li  a,.postContent p a[title],#related_post a,.tipTip[title],.comment-head 	span.name a,.hidbtn,#footer a").tipTip({maxWidth:"240px",defaultPosition:"top",delay:300});
		$("#home,.subscribe a").tipTip({defaultPositition:"bottom",delay:300});		
		$("input[title]").tipTip({activation:"focus",defaultPosition:"right",delay:100});
		$("#totop").tipTip({defaultPosition:"left",delay:300});
		/*scroll to stop animate*/
		$(document).bind("mousewheel",function(e){$('html,body').stop()}); 	
	});
	/*smart scroll*/
	$("#totop").css({'display':'none'});
    $(document).scroll(function () {
       		if ($(this).scrollTop() > 88) {
            		$("#scroll").addClass("fixed-scroll");
					$("#totop").css({'display':'inline'});
        	} else {
            		$("#scroll").removeClass("fixed-scroll");
					$("#totop").css({'display':'none'}).blur();
			}		        
	});
	$("#searchform2 input").focus(function(){$(this).animate({width:'200px'},'slow')});
	$("#searchform2 input").blur(function(){$(this).animate({width:'88px'},'slow')});
	$(".postWrapper").hover(function(){$(this).find('.more-link').addClass('hover')},function(){$(this).find('.more-link').removeClass('hover')});
	
/*Part III End*/
</script>

</html>