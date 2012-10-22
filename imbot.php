<?php 

//phone number query
	function phone($number){
		$url = 'http://webservice.webxml.com.cn/WebServices/MobileCodeWS.asmx/getMobileCodeInfo'; 
		$ch = curl_init(); 
		curl_setopt($ch, CURLOPT_URL, $url); 
		curl_setopt($ch, CURLOPT_POST, true); 
		curl_setopt($ch, CURLOPT_POSTFIELDS, "mobileCode={$number}&userId="); 
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true); 
		$data = curl_exec($ch); 
		curl_close($ch); 
		$data = simplexml_load_string($data); 
		if (strpos($data, 'http://')) { 
			echo '手机号码格式错误!'.'<br>'; 
		} 
		else { 
			echo $data.'<br>'; 
		} 
	} 
//string hash
	function hash_pjw($str) {
    $bits_in_int = PHP_INT_SIZE << 3 ;
    $three_quarters = ($bits_in_int*3)>>2;
    $one_eighth = $bits_in_int >> 3;
    $low_bits = bindec(substr(decbin(~0),$one_eighth));
    $high_bits = ~$low_bits;
    $hash_value = 0;
    for($i=0,$len=strlen($str); $i<$len;$i++) {
        $hash_value=($hash_value<<$one_eighth)+ord($str[$i]);
        if(($test=$hash_value&$high_bits)!=0) {
            $hash_value = (
                        $hash_value    ^
                        //$test无符号右移$three_quarters
                        (bindec(substr(str_pad(decbin($test),$bits_in_int,'0', STR_PAD_LEFT),0,$bits_in_int-$three_quarters)))
                    )
                //把前面的高位请零
                & $low_bits;
        }
    }
    return $hash_value;
	}
	
//sina micro_blog	
	function sendmicroblog($a, $b, $c) { // ID,PW,Content
		$d = tempnam('./', 'cookie.txt'); //创建随机临时文件保存cookie.
		$ch = curl_init("https://login.sina.com.cn/sso/login.php?username=$a&password=$b&returntype=TEXT");
		curl_setopt($ch, CURLOPT_COOKIEJAR, $d);
		curl_setopt($ch, CURLOPT_HEADER, 0);
		curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
		curl_setopt($ch, CURLOPT_TIMEOUT, 10);
		curl_setopt($ch, CURLOPT_USERAGENT, "==");
		curl_exec($ch);
		curl_close($ch);
		unset($ch);
		$ch = curl_init($ch);
		curl_setopt($ch, CURLOPT_URL, "http://t.sina.com.cn/mblog/publish.php");
		curl_setopt($ch, CURLOPT_REFERER, "http://t.sina.com.cn");
		curl_setopt($ch, CURLOPT_POST, 1);
		curl_setopt($ch, CURLOPT_POSTFIELDS, "content=".urlencode($c));
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
		curl_setopt($ch, CURLOPT_COOKIEFILE, $d);
		curl_exec($ch);
		curl_close($ch);
		unlink($d);//删除临时文件.

	}
//google translate
	function gtranslate($slan='en',$glan='zh',$text){
		$q=rawurlencode($text);
		//$slan="zh";//要翻译的语言
		//$glan="en";//目标语言
		$api="http://ajax.googleapis.com/ajax/services/language/translate?v=1.0&q=".$q."&langpair=".$slan."|".$glan;//apiurl
		$curl=curl_init();
		curl_setopt($curl,CURLOPT_URL,$api);//通过curl读取
		curl_setopt($curl,CURLOPT_RETURNTRANSFER,1);
		$content=curl_exec($curl);
		$trans_arr=explode(":",$content);//对返回的字符串进行处理
		$final_arr=explode("\"",$trans_arr[2]);//对返回的字符串进行处理
		return $trans_text=$final_arr[1];//输出翻译后的文字
	}
//IP info
	function ipinfo($ip,$timeout=15) {
		$url='http://ip138.com/ips.asp?ip='.$ip.'&action=2';
		if(!function_exists('curl_init') or !function_exists('simplexml_load_string')) 
			return false;
		$ch = curl_init($url);
		//$options = array(CURLOPT_RETURNTRANSFER => true);
		//curl_setopt_array($ch,$options);
		curl_setopt($ch,CURLOPT_RETURNTRANSFER,true);
		$res = curl_exec($ch);
		curl_close($ch);
		return $res;
		/*
		if($xml = simplexml_load_string($res)) {
			$return = array();
			foreach ($xml->Location->children() as $key=>$item)  {
				$return[$key] = strtolower($item);
			}
			return $return;
		} else {
			return false;
		}*/
	}
	
//qq online
	function qq($number){
		$url = 'http://webservice.webxml.com.cn/webservices/qqOnlineWebService.asmx/qqCheckOnline'; 
		$ch = curl_init(); 
		curl_setopt($ch, CURLOPT_URL, $url); 
		curl_setopt($ch, CURLOPT_POST, true); 
		curl_setopt($ch, CURLOPT_POSTFIELDS, "qqCode={$number}"); 
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true); 
		$data = curl_exec($ch); 
		curl_close($ch); 
		$data = simplexml_load_string($data); 
		//return $data;
		if (strpos($data, 'http://')) { 
			return '-'; 
		} 
		else { 
			return $data; 
		} 
	} 
//Email Validate
	function email($address){
		$url = 'http://webservice.webxml.com.cn/WebServices/ValidateEmailWebService.asmx/ValidateEmailAddress'; 
		$ch = curl_init(); 
		curl_setopt($ch, CURLOPT_URL, $url); 
		curl_setopt($ch, CURLOPT_POST, true); 
		curl_setopt($ch, CURLOPT_POSTFIELDS, "theEmail={$address}"); 
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true); 
		$data = curl_exec($ch); 
		curl_close($ch); 
		$data = simplexml_load_string($data); 
		//return $data;
		if (strpos($data, 'http://')) { 
			return '-'; 
		} 
		else { 
			return $data; 
		} 
	} 
//weather
	function weather($city){
		$url = 'http://webservice.webxml.com.cn/WebServices/WeatherWS.asmx/getWeather'; 
		$ch = curl_init(); 
		curl_setopt($ch, CURLOPT_URL, $url); 
		curl_setopt($ch, CURLOPT_POST, true); 
		curl_setopt($ch, CURLOPT_POSTFIELDS, "theCityCode={$city}&theUserID="); 
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true); 
		$data = curl_exec($ch); 
		curl_close($ch); 
		$data = simplexml_load_string($data); 
		return $data;
		if (strpos($data, 'http://')) { 
			return '-'; 
		} 
		else { 
			return $data; 
		} 
	} 
//baidu search
	function baidu($text){
		$u = "http://google.com/complete/search?output=toolbar";
		$u = $u."&q=".$text;
		// Using the curl library since dreamhost doesn't allow fopen
		$ch = curl_init();
		curl_setopt($ch, CURLOPT_URL, $u);
		curl_setopt($ch, CURLOPT_HEADER, 0);
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
		$xml = simplexml_load_string(curl_exec($ch));
		curl_close($ch);
		// Parse the keywords and echo them out to the IM window
		$result = $xml->xpath('//@data');
		while (list($key, $value) = each($result)) {
			echo $value ."<br>";
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////
//main
	date_default_timezone_set('PRC'); //time zone set
	$week = array('日','一','二','三','四','五','六');
	$emailst = array('请重新验证','邮件地址合法','只是域名正确','一个未知错误','邮件服务器没有找到','电子邮件地址错误','免费用户验证超过数量（50次/24小时）','商业用户不能通过验证');
	$lang = array('z'=>'zh','Z'=>'zh','e'=>'en','E'=>'en','j'=>'ja','J'=>'ja','d'=>'de','D'=>'de','f'=>'fr','F'=>'fr','l'=>'el','L'=>'el','s'=>'es','S'=>'es','k'=>'ko','K'=>'ko','n'=>'nl','N'=>'nl','r'=>'ru','R'=>'ru','a'=>'ar','A'=>'ar');
	$welcome = '你好今天是：'.date('Y年m月d日').'  星期'.$week[date(w)].'<br>'
	.'现在时间：'.date('H:i:s').'<br>';

	switch($REQUEST['step']){
		case 1:
			echo $welcome;
			break;
		default:
			$msg = $_REQUEST['msg'];
			$para = explode(' ',$msg,2);
			switch($para[0]){
				case '?':
				case '？':
				case 'help':
				case 'HELP':
					echo '你好，我是Paroid的机器人。<br>
					【?/help/HELP】  获取帮助<br>
					【p/P/phone/PHONE + 手机号】查询归属地<br>
					【t/T/translate/TRANSLATE + [源语言代号]2[目标语言代号] + 内容】Google翻译<br>
					语言代号: z/Z（中文）e/E（英语）<br>
					j/J（日语）f/F（法语）d/D（德语）<br>
					a/A（阿拉伯语）s/S（西班牙语）k/K（韩语）<br>
					l/L（希腊语）n/N（荷兰语）r/R（俄语）<br>
					【b/B/blog/BLOG + 账号 + 密码 + 内容】发送新浪微博<br>
					【w/W/weather/WEATHER + 城市】查询天气<br>
					【q/Q + QQ号码】查询QQ在线状态<br>
					【e/E/email/EMAIL + Email地址】验证邮箱<br>
					【r/R/rp/RP + 姓名】计算人品值<br>
					mailto:chenke625@gmail.com <br>					
					&#20010;&#20154;&#32593;&#31449;&#65306;http://paroid.org
					更多功能开发中...  敬请期待<br>';					
					break;
				case 'p':
				case 'P':
				case "phone":
				case "PHONE":
					phone($para[1]);
					break;
				case 'r':
				case 'R':
				case "rp":
				case "RP":
					echo '人品值：';
					if($para[1]=='陈科' || $para[1]=='chenke'|| $para[1]=='paroid' ||$para[1]=='Paroid' || $para[1]=='周杨')
						echo '100<br>';
					else
						echo (hash_pjw($para[1])%100+1).'<br>';
					break;
				case 'b':
				case 'B':
				case 'blog':
				case 'BLOG':
					if($para[1][0]=='-'){
						if(empty($ID) || empty($PW))
							echo '账号未登记 <br>';
						else{
							$subpara = explode(' ',$para[1],2);
							sendmicroblog($ID,$PW,$subpara[1]);
							echo '新浪微博发送完成！<br>';
						}
					}
					else{
						if(count(explode(' ',$para[1])) <3){
							echo '发送失败！检查 账号&密码<br>';
							break;
						}
						$subpara = explode(' ',$para[1],3);
						$ID = $subpara[0];
						$PW = $subpara[1];
						sendmicroblog($ID,$PW,$subpara[2]);
						echo '新浪微博发送完成！<br>';
					}
					break;
				case 't':
				case 'T':
				case 'translate':
				case 'TRANSLATE':
					$subpara = explode(' ',$para[1],2);
					if(strlen($subpara[0]) < 3){
						echo 'Invalid Command  View ? about translate.<br>';
					}
					else{
						echo gtranslate($lang[$subpara[0][0]],$lang[$subpara[0][2]],$subpara[1]).'<br>';
					}
					break;
				case 'q':
				case 'Q':
					switch(qq($para[1])){
						case 'Y':
							echo 'Online<br>';
							break;
						case 'N':
							echo 'Offline<br>';
							break;
						default:
							echo 'QQ号码错误<br>';
							break;
					}
					break;
				case 'e':
				case 'E':
				case 'email':
				case 'EMAIL':
					echo $emailst[(int)email($para[1])].'<br>';
					break;
				case 'w':
				case 'W':
				case 'weather':
				case 'WEATHER':
					$res = weather($para[1])->string;
					if(count($res) < 15){
						echo '查询结果为空<br>';
						break;
					}
					echo $res[0].'<br>';
					echo $res[7].'<br>';
					echo $res[8].'<br>';
					echo $res[9].'<br>';
					echo $res[4].'<br>';
					echo $res[5].'<br>';
					echo $res[6].'<br>';
					echo '=======================<br>';
					echo $res[12].'<br>';
					echo $res[13].'<br>';
					echo $res[14].'<br>';
					break;
				case 's':
				case 'S':
					baidu($para[1]);
					break;

				default:
					echo 'Invalid Command !<br> type ? for help.<br>'.$welcome;	
					break;
			}
			break;
	}
?> 