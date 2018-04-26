jQuery(document).ready(function()
{
	var urlt=window.location.href;
	/*board-and-staff page*/
	if(urlt=="https://www.leftforum.org/board-and-staff")
	{ 
		var width=jQuery(window).width();
		var height=jQuery(window).height();
		
		if(width<'768')
		{ 
			jQuery('.view-id-board_and_staff table tr td').each(function()
			{ 
				var a =jQuery(this).find(".views-field.views-field-field-speaker1-biography").html();
				jQuery(this).find(".views-field.views-field-field-speaker1-biography").remove();
				jQuery('<div class="views-field views-field-field-speaker1-biography">'+ a +'</div>').insertAfter(jQuery(this).find(".views-field.views-field-field-speaker1-affiliation"));
				jQuery('.board-staff .views-field-field-speaker1-biography').css('width','100%');
				jQuery('.page-board-and-staff .page-header').css('top','-140px!important');
				jQuery('.page-board-and-staff .page-header').css('font-size','21px !important');
				
				/**affiliation*/
				var t=jQuery(this).find(".views-field-field-speaker1-affiliation").html();
				jQuery(this).find(".views-field.views-field-field-speaker1-affiliation").remove();
				jQuery('<div class="views-field views-field-field-speaker1-affiliation">'+ t +'</div>').insertAfter(jQuery(this).find(".views-field.views-field-title"));
				
				

			});
			
		}
	}
	if(urlt="https://www.leftforum.org/advisory-board")
	{
		jQuery(".region.region-content #block-system-main").append(jQuery(".views-field.views-field-view"));
	}
	/*event submission node */
	var evnsuburlt=window.location.href;
	var tt=evnsuburlt.substr(0,evnsuburlt.lastIndexOf('/'));
	if(tt=='https://www.leftforum.org/sessions')
	{
		jQuery("<div class='speakerdata'><div class='sdata-1'></div><div class='sdata-2'></div><div class='sdata-3'></div><div class='sdata-4'></div><div class='sdata-5'></div></div>").insertAfter(".field.field-name-field-image-speaker-1.field-type-image.field-label-hidden"); 
		k=0;jQuery(".field-name-field-image-speaker-1 .field-item").each(function(){ img= jQuery(this).html(); k++; jQuery(".speakerdata .sdata-"+k+"").append(img);});	

		i=0;jQuery(".field-name-field-speaker1-first-name .field-item").each(function(){ frsn= jQuery(this).html(); i++; jQuery(".speakerdata .sdata-"+i+"").append("<p>"+frsn+"</p>");   });
		j=0;jQuery(".field-name-field-speaker-last-name .field-item").each(function(){lstn= jQuery(this).html(); j++; jQuery(".speakerdata .sdata-"+j+"").append("<p>"+lstn+"</p>");   });
		n=0;jQuery(".field-name-field-middle-initial .field-item").each(function(){ mstn= jQuery(this).html(); n++; jQuery(".speakerdata .sdata-"+n+"").append("<p>"+mstn+"</p>");});	

		l=0;jQuery(".field-name-field-speaker1-affiliation .field-item").each(function(){ aff= jQuery(this).html(); l++; jQuery(".speakerdata .sdata-"+l+"").append("<p>"+aff+"</p>");   });
		m=0;jQuery(".field-name-field-speaker1-biography .field-item").each(function(){ bio= jQuery(this).html(); m++; jQuery(".speakerdata .sdata-"+m+"").append("<p class='inner-bio' id="+m+">"+bio+"</p>");});
		//s=0;jQuery(".field-name-field-image-speaker-1 .field-item").each(function(){ bio= jQuery(this).html(); s++; jQuery(".speakerdata .sdata-"+s+"").append("<button class='read-mr'>Read More</button><a class='read-mr' href='#'>Read More </a>");});	
		s=0;jQuery(".field-name-field-image-speaker-1 .field-item").each(function(){ bio= jQuery(this).html(); s++; jQuery(".speakerdata .sdata-"+s+"").append("<button style='color: #fff;background: #ff3e33;padding: 4px 9px;border-radius: 3px;font-size: 14px;' class='read-mr'>Read More</button>");});	

		/*hide empty portion*/
		var sdata1=jQuery('.sdata-1').html();
		if(!sdata1)
		{
			jQuery('.sdata-1').css('display','none');
		}	
		var sdata2=jQuery('.sdata-2').html();
		if(!sdata2)
		{
			jQuery('.sdata-2').css('display','none');
		}
		var sdata3=jQuery('.sdata-3').html();
		if(!sdata3)
		{
			jQuery('.sdata-3').css('display','none');
		}
		var sdata4=jQuery('.sdata-4').html();
		if(!sdata4)
		{
			jQuery('.sdata-4').css('display','none');
		}	
		var sdata5=jQuery('.sdata-5').html();
		if(!sdata5)
		{
			jQuery('.sdata-5').css('display','none');
		}

		jQuery('button').click(function()
		{
			var test=jQuery(this).prev().attr('id');
			jQuery(this).prev().removeClass('inner-bio');
		});
		
		/*Forum Type*/
		var forumtype=jQuery('.field-name-field-forum-type .field-item').html();
		
		if(forumtype=='CREATIVITY FORUM')
		{
			jQuery('.field-name-field-forum-type').css('background','#ff9900');
		}
		else if(forumtype=='ECONOMY FORUM')
		{
			jQuery('.field-name-field-forum-type').css('background','#3d85c6');
		}
		else if(forumtype=='POLICY FORUM')
		{
			jQuery('.field-name-field-forum-type').css('background','#ffd966');
		}
		else if(forumtype=='RACE FORUM')
		{
			jQuery('.field-name-field-forum-type').css('background','#ff00ff');
		}
		else if(forumtype=='GENDER FORUM')
		{
			jQuery('.field-name-field-forum-type').css('background','#9900ff');
		}
		else if(forumtype=='PLANET FORUM')
		{
			jQuery('.field-name-field-forum-type').css('background','#6aa84f');
		} 
		
	}	
	/*Page header */
	var pghd=jQuery('.page-header').html();
	jQuery('<h1 class="page-header">'+pghd+'</h1>').insertAfter('.featured-image-container img');
	jQuery('.row .page-header').css('display','none');
	/*register*/
	jQuery('#block-bootstrap-login-modal-bootstrap-login-modal li:nth-child(2) a').text('create account');

});
