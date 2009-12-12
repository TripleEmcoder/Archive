/* Code first created by Zewa,
 * fixed up by AlexisWilke so it works with any type of page
 */
/**
* Reply, Edit & Delete buttons for included comments.
*
* Store where the user was when clicking add comment or reply,
* and bring him or her back there afterwards.
*/
function node_insert_destination(link){
  attr=jQuery(link).attr('href');
  attr+=attr.indexOf('?')==-1?'?':'&';
  url=location.pathname.substring(1);
  jQuery(link).attr('href',attr+'destination='+url);
}
jQuery("a[href*='comment/reply'],a[href*='comment/edit'],a[href*='comment/delete']").click(function(){node_insert_destination(this);});
