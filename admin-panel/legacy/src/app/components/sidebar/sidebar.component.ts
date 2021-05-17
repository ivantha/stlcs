import {Component, OnInit} from '@angular/core';
import {MenuItem} from 'primeng/api';

import {SIDEBAR_ITEMS} from './sidebar.items';

@Component({
    selector: 'app-sidebar',
    templateUrl: './sidebar.component.html',
    styleUrls: ['./sidebar.component.sass']
})
export class SidebarComponent implements OnInit {

    items: MenuItem[];

    constructor() {
    }

    ngOnInit() {
        this.items = SIDEBAR_ITEMS;
    }

}
