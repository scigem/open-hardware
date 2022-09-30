$fn=80 ;

module m4hole(location) {
translate(location) 
rotate([0,180,0]) 
    {
        union()
        {
        cylinder(d=3.1, h=100) ; 
        cylinder(d=8, h=5) ; 
        }
    }
} 

bot=2 ;
lip=10 ; 

// Part 1
!difference() {
cube([100,70,10+bot+lip+3]) ; 
    #translate([-1,2,10+bot+0.01]) cube([102,66,lip+1.5]) ; 
    translate([-1,2+2,10+bot+0.01+3]) cube([102,62,lip]) ; 
    translate([20,5,bot]) cube([60,60,21 ]) ;
    m4hole([10,20,10+bot+0.02]) ; 
    m4hole([10,50,10+bot+0.02]) ; 
    m4hole([90,20,10+bot+0.02]) ; 
    m4hole([90,50,10+bot+0.02]) ; 
    
    translate([10,20, 0]) cylinder(d=3.1, h=100, center=true) ; 
    translate([10,50, 0]) cylinder(d=3.1, h=100, center=true) ; 
    translate([90,20, 0]) cylinder(d=3.1, h=100, center=true) ; 
    translate([90,50, 0]) cylinder(d=3.1, h=100, center=true) ; 
}


offset=0 ;
//Part 2
color("blue") difference() {
translate([offset,2.5,10+bot]) cube([100,65,10]) ; 
translate([20+offset,5,bot]) cube([60,60,21]) ;
    
translate([offset+100+50-15,35,10+bot+5]) rotate([0,90,0]) cylinder(d=2.6, h=100, center=true) ;
}

//Part 3
translate([offset+20+0.5, 5+0.5, 15])
union() {
cube([60-1,60-1,5]) ; 
translate([1,1,0]) cube([10,5,25]) ; 
}








